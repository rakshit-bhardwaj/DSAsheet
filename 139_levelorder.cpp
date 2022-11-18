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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lvlorder(40);
        findlvlorder(root,0,lvlorder);
        vector<vector<int>> ans;
        for(auto i: lvlorder){
            if(i.size()!=0) ans.push_back(i);
            else break;
        }
        return ans;
    }

    void findlvlorder(TreeNode* root,int lvl,vector<vector<int>> &lvlorder){
        if(root==NULL) return;
        lvlorder[lvl].push_back(root->val);
        findlvlorder(root->left,lvl+1,lvlorder);
        findlvlorder(root->right,lvl+1,lvlorder);
    }
};