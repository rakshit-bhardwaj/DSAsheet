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
    TreeNode* tree(vector<int> nums,int s,int e){
        if(s>e) return NULL;
        int mid = (s+e)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = tree(nums,s,mid);
        temp->right = tree(nums,mid,e);
        return temp;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return tree(nums,0,nums.size()-1);
    }
};

// 0 1 2 3 4 5

  