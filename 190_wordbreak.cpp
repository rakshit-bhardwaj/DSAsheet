#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> children;
    bool isLeaf;

    TrieNode()
    {
        children.resize(26);
        isLeaf = false;
    }
};

void insert(TrieNode *root, string key)
{
    TrieNode *cur = root;
    for (int i = 0; i < key.size(); i++)
    {
        char c = key[i];
        if (cur->children[c - 'a'] == NULL)
        {
            TrieNode *n = new TrieNode();
            cur->children[c - 'a'] = n;
        }
        cur = cur->children[c - 'a'];
    }
    cur->isLeaf = true;
}

bool searchkey(TrieNode *root, string key)
{
    TrieNode *cur = root;
    for (int i = 0; i < key.size(); i++)
    {
        char c = key[i];
        if (cur->children[c - 'a'] == NULL)
            return false;
        cur = cur->children[c - 'a'];
    }
    return cur->isLeaf;
}

class Solution
{
public:
    TrieNode *createtrie(vector<string> &dict)
    {
        TrieNode *root = new TrieNode();
        for (auto x : dict)
            insert(root, x);
        return root;
    }

    bool solve(TrieNode *root, string s, vector<string> &dict)
    {
        if (s.size() == 0)
            return true;
        for (int i = 1; i <= s.size(); i++)
        {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i, s.size() - i);
            if (searchkey(root, s1) && solve(root, s2, dict))
                return true;
        }
        return false;
    }
};

int main()
{
    vector<string> dict = {"mobile", "samsung", "sam", "sung", "ma", "mango", "icecream", "and", "go", "i", "like", "ice", "cream"};
    Solution o;
    TrieNode *n = o.createtrie(dict);

    o.solve(n, "ilikesamsung", dict) ? cout << "Yes\n"
                                     : cout << "No\n";
    o.solve(n, "iiiiiiii", dict) ? cout << "Yes\n"
                                 : cout << "No\n";
    o.solve(n, "", dict) ? cout << "Yes\n" : cout << "No\n";
    o.solve(n, "ilikelikeimangoiii", dict) ? cout << "Yes\n"
                                           : cout << "No\n";
    o.solve(n, "samsungandmango", dict) ? cout << "Yes\n"
                                        : cout << "No\n";
    o.solve(n, "samsungandmangok", dict) ? cout << "Yes\n"
                                         : cout << "No\n";

    return 0;
}