#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left,*right;
};

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    
    int findDist(Node* root, int a, int b) {
        if(a==b) return 0;
        vector<Node*> pa,pb,tpath;
        dfs(root,a,pa,tpath);
        dfs(root,b,pb,tpath);
        int sa = pa.size();
        int sb = pb.size();

        if(sb > sa){
            vector<Node*> temp = pb;
            pb = pa;
            pa = temp;
            int temp1 = b;
            b = a;
            a = temp1;
            int temp2 = sb;
            sb = sa;
            sa = temp2;
        }

        if(pa[sb-1]->data == b) return sa - sb;
        
        for(int i = sa - 1;i>=0;i--){
            if(pa[i]->data == pb[i]->data){
                return sa + sb - 2*i - 2;
            }
        }

    }

    void dfs(Node* root,int a,vector<Node*> &path,vector<Node*> tpath){
        if(root==NULL) return;
        tpath.push_back(root);
        if(root->data == a) {
            path = tpath;
            return;
        }
        dfs(root->left,a,path,tpath);
        dfs(root->right,a,path,tpath);
    }
};

