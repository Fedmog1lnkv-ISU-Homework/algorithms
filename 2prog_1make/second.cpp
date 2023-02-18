#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#define M_PI 3.14159265358979323846 /* pi */

int main(int argc, char *argv[])
{
    std::string filename(argv[1]);

    std::ifstream file_in(filename);
    if (!file_in)
    {
        return -1;
    }

    std::string line;
    double x, y, z;
    file_in >> x >> y >> z;
    while (file_in)
    {
        double angle = 2 * sin(x) * sin(y) + cos(z);
        std::cout << angle << std::endl;
        file_in >> x >> y >> z;
    }
    file_in.close();
    return 0;
}