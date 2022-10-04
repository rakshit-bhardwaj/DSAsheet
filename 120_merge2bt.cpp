#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void merge(TreeNode* n1,TreeNode* n2){
        if(n1==NULL && n2==NULL) return;
        if(n1!=NULL && n2!=NULL) {
            n1->val = n1->val + n2->val;
            if(n1->left!=NULL && n2->left!=NULL) merge(n1->left,n2->left);
            if(n1->right!=NULL && n2->right!=NULL) merge(n1->right,n2->right);
            if(n1->left==NULL && n2->left!=NULL) n1->left = n2->left;
            if(n1->right==NULL && n2->right!=NULL) n1->right = n2->right;
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL) return root2;
        merge(root1,root2);
        return root1;
    }
};