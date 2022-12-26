#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node* prev = NULL,*head = NULL;
    Node * bToDLL(Node *root)
    {
        convert(root);
        return head;
    }
    void convert(Node* root){
        if(root==NULL) return;
        convert(root->left);
        if(prev == NULL) head = root;
        else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        convert(root->right);
    }
};
