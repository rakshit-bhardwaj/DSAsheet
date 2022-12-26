#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left,*right;
};

Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    int gsize = 0;
    int preind = 0;
    Node* post_order(int pre[], int size)
    {
        vector<int> pr,in;
        gsize = size;
        for(int i = 0;i<size;i++){
            pr.push_back(pre[i]);
        }
        in = pr;
        sort(in.begin(),in.end());
        map<int,int> inmap;
        for(int i =0;i<in.size();i++){
            inmap[in[i]] = i;
        }
        return constructbst(pre,0,size-1,inmap);
    }

    Node* constructbst(int pre[],int s,int e,map<int,int> inmap){
        if(s>e || preind>=gsize) return NULL;
        int cur = pre[preind++];
        Node* root = newNode(cur);
        if(s==e) return root;
        int indin = inmap[cur];
        root->left = constructbst(pre,s,indin-1,inmap);
        root->right = constructbst(pre,indin+1,e,inmap);
        return root;
    }
};

// 40 30 35 80 100 preorder
// 30 35 40 80 100 inorder (sorted)



