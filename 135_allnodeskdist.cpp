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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> par;
        getparents(root,par,NULL);
        map<int,int> visited;

        queue<TreeNode*> q;
        q.push(target);
        visited[target->val] = 1;
        int dist = 0;
        while(!q.empty()){
            if(dist++==k) break;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                visited[node->val] = 1;
            
                if(node->left!=NULL && visited[node->left->val]==0) q.push(node->left);
                if(node->right != NULL && visited[node->right->val]==0) q.push(node->right);
                if(par[node]!=NULL && visited[par[node]->val]==0) q.push(par[node]);
            }   
        }
        vector<int> ans;
        while(!q.empty()){
            int cur = q.front()->val;
            q.pop();
            ans.push_back(cur);
        }
        return ans;
    }

    void getparents(TreeNode* root,map<TreeNode*,TreeNode*> &par,TreeNode* p){
        if(root==NULL) return;
        par[root] = p;
        getparents(root->left,par,root);
        getparents(root->right,par,root);
    }

};