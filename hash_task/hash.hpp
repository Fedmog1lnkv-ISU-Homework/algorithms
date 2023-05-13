#ifndef HASH_HPP
#define HASH_HPP

#include <map>
#include <algorithm>
#include <chrono>

static std::map<char, int> r;

void fill_map()
{
    srand(time(NULL));
    for (int i = 'A'; i < 'z'; i++)
        r[i] = rand();
}

int hash_crc(const std::string &str)
{
    int h = 0;
    for (int i = 0; i < (int)str.length(); i++)
    {
        int highorder = h & 0xf8000000;
        h = h << 5;
        h = h ^ (highorder >> 27);
        h = h ^ str[i];
    }
    return h;
}

int hash_pjw(const std::string &str)
{
    int h = 0;
    for (int i = 0; i < (int)str.length(); i++)
    {
        h = (h << 4) + str[i];
        int g = h & 0xf0000000;
        if (g != 0)
        {
            h = h ^ (g >> 24);
            h = h ^ g;
        }
    }
    return h;
}

int hash_buz(const std::string &str)
{
    int h = 0;
    for (int i = 0; i < (int)str.length(); i++)
    {
        int highorder = h & 0x80000000;
        h = h << 1;
        h = h ^ (highorder >> 31);
        h = h ^ r[str[i]];
    }
    return h;
}

int hash_cpp(const std::string &str)
{
    return std::hash<std::string>{}(str);
}

#endif // HASH_HPP
