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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans = max(ans,max(root->val,max(root->val + left + right,max(root->val + left,root->val + right))));
        return max(root->val,max(root->val + left,root->val + right));
    }
};
