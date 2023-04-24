import json
import shapely
import math
import networkx as nx


def get_clusters(spanning_tree: nx.Graph, n_clusters: int):
    components = list(nx.connected_components(spanning_tree))
    edges = sorted(spanning_tree.edges(data=True), key=lambda x: x[2]['weight'], reverse=True)
    for u, v, weight in edges:
        if n_clusters - 1 == len(components):
            break
        if u not in components[v] and v not in components[u]:
            components.append(components[u].union(components[v]))
            components.remove(components[u])
            components.remove(components[v])
    return components


def split_to_forests(graph, count_clusters=40):
    forest = nx.minimum_spanning_tree(graph)
    for _ in range(count_clusters - 1):
        max_edge = max(forest.edges, key=lambda x: forest.get_edge_data(*x)["weight"])
        forest.remove_edge(*max_edge)
    return [forest.subgraph(c) for c in nx.connected_components(forest)]


def distance(site1, site2):
    loc1, loc2 = site1["location"], site2["location"]
    phi1, phi2 = math.radians(loc1["lat"]), math.radians(loc2["lat"])

    dphi = math.radians(loc2["lat"] - loc1["lat"])
    dlambda = math.radians(loc2["lon"] - loc1["lon"])

    a = math.sin(dphi / 2) ** 2 + math.cos(phi1) * math.cos(phi2) * math.sin(dlambda / 2) ** 2
    return 6371 * 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))


def create_edges(sites, max_distance):
    edges = []
    for i, site in enumerate(sites[:-1]):
        dest = get_closest_site(site, sites[i + 1:], max_distance)
        edges.append((site["code"], dest["code"], distance(site, dest)))
    return edges


def get_closest_site(site, destinations, max_distance):
    closest_dest = None
    min_distance = 10 ** 16
    for dest in destinations:
        dist = distance(site, dest)
        if dist <= max_distance and dist < min_distance:
            closest_dest = dest
            min_distance = dist
    if closest_dest is None:
        closest_dest = destinations[-1]
    return closest_dest


def make_graph(sites, max_distance=400):
    nodes = [site["code"] for site in sites]
    edges = create_edges(sites, max_distance)
    return edges, nodes


if __name__ == "__main__":
    with open("json_files/base.json", "r") as f:
        sites = json.load(f)
        lons = [site["location"]["lon"] for site in sites]
        lats = [site["location"]["lat"] for site in sites]

    with open("json_files/file.json", "r") as f:
        continents = json.load(f)
        north_america_polygon = continents["features"][1]["geometry"]["coordinates"]

    max_polygon = max(north_america_polygon, key=lambda polygon: shapely.Polygon(polygon[0]).area)

    north_america = shapely.Polygon(max_polygon[0])
    north_america_sites = [site for site in sites
                           if north_america.contains(shapely.Point(site["location"]["lon"], site["location"]["lat"]))]

    flons = [site["location"]["lon"] for site in north_america_sites]
    flats = [site["location"]["lat"] for site in north_america_sites]

    edges, nodes = make_graph(north_america_sites)
    graph = nx.Graph()
    graph.add_nodes_from(nodes)
    graph.add_weighted_edges_from(edges)

    num_of_forests = len(split_to_forests(graph, 40))
    print(num_of_forests)
