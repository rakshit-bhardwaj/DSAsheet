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
    
    int widthOfBinaryTree(TreeNode* root) {
      queue<pair<TreeNode*,int>> lvl;
        lvl.push({root,0});
        int ans = 0;
        while(!lvl.empty()){
            int size = lvl.size();
            int curmin = lvl.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                TreeNode* n = lvl.front().first;
                int curid = lvl.front().second - curmin;
                lvl.pop();

                if(i==0) first = curid;
                if(i==size-1) last = curid;

                if(n->left!=NULL) lvl.push({n->left,(long long) curid * 2 + 1});
                if(n->right!=NULL) lvl.push({n->right,(long long) curid *2 + 2});
            }
            ans = max(ans,last-first + 1);
        }
        return ans;
    }
};
