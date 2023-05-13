#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

#include "hash.hpp"

void get_filenames(const std::string &path, std::vector<std::string> &filenames)
{
    for (const auto &entry : std::filesystem::directory_iterator(path))
        if (entry.is_regular_file())
            filenames.push_back(entry.path().string());
}

int find_duplicates(const std::vector<std::string> &filenames, int (*hashfunc)(const std::string &))
{
    std::vector<int> hashes;
    int counter_repeats = 0;
    for (auto filename : filenames)
    {
        std::ifstream file(filename);
        if (!file.is_open())
            return -1;
        std::stringstream buf;
        buf << file.rdbuf();
        int h = hashfunc(buf.str());
        if (std::find(hashes.begin(), hashes.end(), h) != hashes.end())
            counter_repeats++;
        else
            hashes.push_back(h);
        file.close();
    }
    return counter_repeats;
}

int main()
{
    const std::string hash_names[4] = {"CRC", "PJW", "BUZ", "CPP"};
    const std::string path = "out";

    std::vector<std::string> filenames;
    filenames.reserve(600);
    get_filenames(path, filenames);
    fill_map();

    int (*hashes[])(const std::string &) = {hash_crc, hash_pjw, hash_buz, hash_cpp};

    for (int i = 0; i < (int)(sizeof(hashes) / sizeof(hashes[0])) &&
                    i < (int)(sizeof(hash_names) / sizeof(hash_names[0]));
         i++)
    {
        auto time_start = std::chrono::high_resolution_clock::now();

        int counter_files = find_duplicates(filenames, hashes[i]);

        auto time_finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration time = time_finish - time_start;

        printf("%s %5lld ms\tRepeat files: %d\n", hash_names[i].c_str(),
               std::chrono::duration_cast<std::chrono::milliseconds>(time).count(),
               counter_files);
    }
    return 0;
}
