#include<bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
        vector<WordDictionary*> children;
        bool isLeaf;
    WordDictionary() {
        children.resize(26);
        isLeaf = false;
    }
    
    void addWord(string word) {
        WordDictionary *cur = this;
        for(int i=0;i<word.size();i++){
             char c = word[i];
             if(cur->children[c - 'a']==NULL){
                WordDictionary *t = new WordDictionary();
                cur->children[c - 'a'] = t;
             }
             cur = cur->children[c - 'a'];
        }
        cur->isLeaf = true;
    }
    
    bool search(string word) {
        return dfs(this,0,word);
        
    }

    bool dfs(WordDictionary *cur,int i,string word){
        if(i >= word.size()){
            if(cur->isLeaf) return true;
            else return false;
        } 
        if(word[i] == '.'){
            for(int j = 0;j<26;j++){
                if(cur->children[j]!=NULL && dfs(cur->children[j],i+1,word)) return true;
            }
            return false;
        } else {
            char c = word[i];
            if(cur->children[c - 'a'] == NULL) return false;
            return dfs(cur->children[c-'a'],i+1,word);
        }
    }
};