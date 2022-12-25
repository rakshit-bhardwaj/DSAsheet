#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left,*right;
};

class Solution{
public:
int count = 0;
    int getCount(Node *root, int l, int h)
    {
       inorder(root,l,h);
       return count;
    }

    void inorder(Node* root,int l,int h){
        if(root==NULL) return;
        if(root->data>l)
        inorder(root->left,l,h);
        if(root->data>=l && root->data<=h) count ++;
        if(root->data<h)
        inorder(root->right,l,h);
    }
};