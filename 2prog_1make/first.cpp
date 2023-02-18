#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define M_PI 3.14159265358979323846 /* pi */

double get_PI()
{
    return (rand() % 360 - 180) * M_PI / 180;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    int n = std::stoi(argv[1]);
    std::string filename(argv[2]);

    std::ofstream file_out;
    file_out.open(filename);
    if (!file_out)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        file_out << get_PI() << ' ' << get_PI() << ' ' << get_PI();
        if (i != n - 1)
        {
            file_out << std::endl;
        }
    }

    file_out.close();
    return 0;
}