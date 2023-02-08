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

vector<vector<string>> ans;

void dfssearch(TrieNode* root,string s,int i,int e,string cur){ 
    
    cout<<"current "<<s[i]<<endl;
    cout<<"i = "<<i<<" e = "<<e<<endl;
    if(i>=e){
        if(root->isLeaf) ans[e-1].push_back(cur);
        for(int k =0;k<26;k++){
            if(root->children[k]!=NULL) {
                string temp = cur;
                temp.push_back(k + 'a');
                dfssearch(root->children[k],s,i,e,temp);
            }
        }
    }else {
        char c = s[i];
        if(root->children[c - 'a']!=NULL){
            cur.push_back(c);
            dfssearch(root->children[c-'a'],s,i+1,e,cur);
        }
        else return;
    }
    
}

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        ans.resize(s.size());
        string temp;
        TrieNode *node = new TrieNode();
        for(int i =0;i<n;i++) insert(node,contact[i]);
        for(int i =1;i<=s.size();i++){
            cout<<"upto "<<s[i-1]<<endl;
            dfssearch(node,s,0,i,temp);
            if(ans[i-1].size()==0){
                string t = "0";
                ans[i-1].push_back(t);
            }
            
        }
        return ans;        
    }
};