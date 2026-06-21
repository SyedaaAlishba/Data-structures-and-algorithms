#include "Tries.h"
#include <cctype>

// constructor
Trie::Trie()
{
    root = new TrieNode();
}

// insert
void Trie::insert(string word)
{
    TrieNode* node = root;

    for (char c : word)
    {
        if (!isalpha(c)) continue;

        c = tolower(c);
        int index = c - 'a';

        if (!node->children[index])
            node->children[index] = new TrieNode();

        node = node->children[index];
    }

    node->isEnd = true;
}

// dfs helper
void Trie::dfs(TrieNode* node, string prefix, vector<string>& results)
{
    if (!node) return;

    if (node->isEnd)
        results.push_back(prefix);

    for (int i = 0; i < 26; i++)
    {
        if (node->children[i])
        {
            char c = 'a' + i;
            dfs(node->children[i], prefix + c, results);
        }
    }
}

// suggestions
vector<string> Trie::getSuggestions(string prefix)
{
    TrieNode* node = root;

    for (char c : prefix)
    {
        if (!isalpha(c)) return {};

        c = tolower(c);
        int index = c - 'a';

        if (!node->children[index])
            return {};

        node = node->children[index];
    }

    vector<string> results;
    dfs(node, prefix, results);

    return results;
}