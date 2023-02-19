from matplotlib import pyplot as plt

cpp = {"count_elements": [], "size": [], "time": []}
with open("out_files/map_test_out.txt", "r") as file_cpp:
    for line in file_cpp:
        line = list(map(int, line.split()))
        cpp["count_elements"] += [line[0]]
        cpp["size"] += [line[1]]
        cpp["time"] += [line[2]]

py = {"count_elements": [], "size": [], "time": []}
with open("out_files/dict_test_out.txt", "r") as file_py:
    for line in file_py:
        line = list(map(int, line.split()))
        py["count_elements"] += [line[0]]
        py["size"] += [line[1]]
        py["time"] += [line[2]]

ax = plt.subplot(1, 2, 1)
plt.title("Зависимость размера словаря\nот колличества элементов")
plt.xlabel("Количетсво элементов")
plt.ylabel("Размер (байт)")
plt.plot(cpp["count_elements"], cpp["size"], label="C++")
plt.plot(py["count_elements"], py["size"], label="Python")
ax.set_xscale("log")
ax.set_yscale("log")
plt.grid()
plt.legend()

ax = plt.subplot(1, 2, 2)
plt.title("Зависимость времени заполения словаря\nот колличества элементов")
plt.xlabel("Количетсво элементов")
plt.ylabel("Время выполнения(наносекунды)")
plt.plot(cpp["count_elements"], cpp["time"], label="C++")
plt.plot(py["count_elements"], py["time"], label="Python")
ax.set_xscale("log")
ax.set_yscale("log")
plt.grid()
plt.legend()

plt.show()
