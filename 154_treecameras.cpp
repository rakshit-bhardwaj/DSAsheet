#include<bits/stdc++.h>
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
    int ans = 0;
    int minCameraCover(TreeNode* root) {
        if(root->right==NULL && root->left == NULL) return 1;
        if(dfs(root)==-1) return ans +1;
        return ans;
    }

    int dfs(TreeNode* root){
        int lef=1,rig=1;
        if(root->left != NULL) lef = dfs(root->left);
        if(root->right != NULL) rig =  dfs(root->right);
        if(root->left== NULL && root->right == NULL) return -1;
        if(lef == -1 || rig == -1){
            ans ++;
            return 0;
        }
        if(lef == 0 || rig == 0){
            return 1;
        }
        return -1;
    }
};