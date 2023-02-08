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

class Solution{
  public:
    vector<vector<string>> ans;
    set<string> s;
    map<string,int> ind;

    vector<vector<string> > Anagrams(vector<string>& string_list) {
    //    TrieNode* n = new TrieNode();
        for(auto x : string_list){
            //cout<<"orignal string -> "<<x<<endl;
            string temp = x;
            sort(temp.begin(),temp.end());
            cout<<"sorted -> "<<temp<<endl;
            if(s.find(temp)==s.end()){
                //cout<<"no anagram found\n";
                s.insert(temp);
                vector<string> t;
                t.push_back(x);
                ans.push_back(t);
                //cout<<"adding anagram to "<<ans.size()-1<<endl;
                ind[temp] = ans.size()-1;
            } else {
                //cout<<"anagram found at "<<ind[temp]<<endl;
                ans[ind[temp]].push_back(x);
            }
        }
        return ans;
    }
};

int main () {
    Solution o;
    vector<string> s = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> a = o.Anagrams(s);
    for(auto x : a){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}
