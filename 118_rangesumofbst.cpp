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
    int bstsum(TreeNode* root,int low,int high){
        if(root==NULL) return 0;
        if(root->val<low) return bstsum(root->right,low,high);
        if(root->val>high) return bstsum(root->left,low,high);
        return bstsum(root->left,low,high) + bstsum(root->right,low,high) + root->val;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return bstsum(root,low,high);
    }
};