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
    vector<string> binaryTreePaths(TreeNode* root) {
       string cur;
       vector<string> ans;
       if(root->val<0) cur.push_back('-');
       int n = abs(root->val);
       if(n/100 != 0 ) cur.push_back((n/100)%10 + '0');
       if(n/10 != 0 ) cur.push_back((n/10)%10 + '0');
       cur.push_back(n%10 + '0');
       if(root->left != NULL) helper(root->left,ans,cur);
       if(root->right != NULL) helper(root->right,ans,cur);
       if(root->left == NULL && root->right == NULL) ans.push_back(cur);
       return ans;
    }

    void helper(TreeNode* root,vector<string> &ans,string cur){
        cur.append("->");
        if(root->val<0) cur.push_back('-');
        int n = abs(root->val);
        if(n/100 != 0 ) cur.push_back((n/100)%10 + '0');
        if(n/10 != 0 ) cur.push_back((n/10)%10 + '0');
        cur.push_back(n%10 + '0');
        if(root->left != NULL) helper(root->left,ans,cur);
        if(root->right != NULL) helper(root->right,ans,cur);
        if(root->left == NULL && root->right == NULL){
            ans.push_back(cur);
            return;
        }
    }
};