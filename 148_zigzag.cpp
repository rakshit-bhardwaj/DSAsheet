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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        int lr = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> curlvl;
            for(int i=0;i<size;i++){
                TreeNode* cur = q.front();
                q.pop();
                curlvl.push_back(cur->val);
                if(cur->left!=NULL) q.push(cur->left);
                if(cur->right!=NULL) q.push(cur->right);
            }
            
            if(lr == 1){
                reverse(curlvl.begin(),curlvl.end());
                lr = 0;
            } else lr = 1;
            ans.push_back(curlvl);
        }
        return ans;
    }
};