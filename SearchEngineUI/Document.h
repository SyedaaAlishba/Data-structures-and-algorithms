//
// Created by PMYLS on 5/20/2026.
//

#ifndef MINISEARCHENGINE_DOCUMENT_H
#define MINISEARCHENGINE_DOCUMENT_H
#pragma once
#include <string>

using namespace std;

struct Document
{
    int id;
    string filename;
    string content;
};
#endif //MINISEARCHENGINE_DOCUMENT_H