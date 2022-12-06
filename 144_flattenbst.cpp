#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void preorder(TreeNode* root,TreeNode* rightchild){
        if(root==NULL) return;
        TreeNode* temp = root->right;
        if(root->left != NULL){
            root->right = root->left;
            root->left = NULL;
            preorder(root->right,temp);
        } else if(root->right==NULL) root->right = rightchild;
        preorder(root->right,rightchild);
    }
    void flatten(TreeNode* root) {
        preorder(root,NULL);
    }
};