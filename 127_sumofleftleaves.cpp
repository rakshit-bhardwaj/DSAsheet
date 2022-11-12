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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        helper(root,ans,0);
        return ans;
    }
    void helper(TreeNode* n,int &ans,int lr){
        if(n->left == NULL && n->right == NULL){
            if(lr) ans += n->val;
            return;
        }
        if(n->left!=NULL) helper(n->left,ans,1);
        if(n->right!=NULL) helper(n->right,ans,0);
    }
};