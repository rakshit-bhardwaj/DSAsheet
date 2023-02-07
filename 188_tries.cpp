#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public : 
    vector<TrieNode*> children;
    bool isLeaf;

    TrieNode() {
        children.resize(26);
        isLeaf = false;
    }

};

void insert(TrieNode *root,string key){
    TrieNode *cur = root;
    for(int i =0;i<key.size();i++){
        char c = key[i];
        if(cur->children[c - 'a'] == NULL){
            TrieNode *n = new TrieNode();
            cur->children[c-'a'] = n;
        }
        cur = cur->children[c-'a'];
    }
    cur->isLeaf = true;
}

bool searchkey(TrieNode *root,string key){
    TrieNode *cur = root;
    for(int i=0;i<key.size();i++){
        char c = key[i];
        if(cur->children[c - 'a']==NULL) return false;
        cur = cur->children[c - 'a'];
    }
    return cur->isLeaf;
}