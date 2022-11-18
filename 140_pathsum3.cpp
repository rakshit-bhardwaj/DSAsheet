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
    
    int pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        unordered_map<long long,int> prefixsum;
        long long ans = 0;
        findallpaths(root,prefixsum,targetSum,0,ans);
        return ans;
    }

    void findallpaths(TreeNode* root,unordered_map<long long,int> prefixsum,int targetSum,long long sum,long long &ans){
        if(root==NULL) return;
        sum+=root->val;
        if(sum==targetSum) ans++;
        if(prefixsum[sum - targetSum] != 0) ans += prefixsum[sum-targetSum];
        prefixsum[sum]++;
        if(root->left!=NULL) findallpaths(root->left,prefixsum,targetSum,sum,ans);
        if(root->right!=NULL) findallpaths(root->right,prefixsum,targetSum,sum,ans);
        return;
    }

};