#include <bits/stdc++.h>
using namespace std;

struct Node {
int data;
Node * right, * left;
};

bool helper(Node *root,Node *par,map<int,int> &ex){
    if(root==NULL) return false;
    ex[root->data] = 1;
    bool left=false,right=false;
    if(root->left == NULL && root->right == NULL){
        if(root->data>1 && ex[root->data-1] == 1 && ex[root->data+1] == 1) return true;
        else if(root->data == 1 && ex[root->data+1] == 1) return true;
    }
    if(root->left != NULL) left = helper(root->left, root,ex);
    if(root->right != NULL) right = helper(root->right,root,ex);
    return left || right; 
}

bool isDeadEnd(Node *root)
{   
    map<int,int> ex;
    ex[root->data] = 1;
    return helper(root->left,root,ex) || helper(root->right,root,ex);
}