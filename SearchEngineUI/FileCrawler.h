#ifndef MINISEARCHENGINE_FILECRAWLER_H
#define MINISEARCHENGINE_FILECRAWLER_H
#pragma once
#include <vector>
#include <string>

using namespace std;

class FileCrawler
{
public:
    vector<string> getFiles(const string& folderPath);
};
#endif //MINISEARCHENGINE_FILECRAWLER_H