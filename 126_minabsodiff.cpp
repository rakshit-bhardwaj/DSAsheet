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
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        vector<int> path;
        preorder(root,path);
        for(int i = 1;i<path.size();i++){
            ans = min(abs(path[i]-path[i-1]),ans);
        }
        return ans;
    }
    
    void preorder(TreeNode* root,vector<int> &path){
        if(root==NULL) return;
        preorder(root->left,path);
        path.push_back(root->val);
        preorder(root->right,path);
    }
    
};