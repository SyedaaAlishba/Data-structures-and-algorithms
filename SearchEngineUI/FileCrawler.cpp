#include "FileCrawler.h"

#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = filesystem;

vector<string> FileCrawler::getFiles(const string& folderPath)
{
    vector<string> files;

    // CHECK IF FOLDER EXISTS
    if (!fs::exists(folderPath))
    {
        cout << "Folder not found: " << folderPath << endl;
        return files;
    }

    // LOOP THROUGH FILES
    for (const auto &entry : fs::directory_iterator(folderPath))
    {
        if (entry.is_regular_file())
        {
            files.push_back(entry.path().string());
        }
    }

    return files;
}