#pragma once

#include <vector>
#include <string>

using namespace std;

class TrieNode
{
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie
{
private:
    TrieNode* root;

    void dfs(TrieNode* node, string prefix, vector<string>& results);

public:
    Trie();
    void insert(string word);
    vector<string> getSuggestions(string prefix);
};