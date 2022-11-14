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
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> preord,preordsort;
        map<int,int> vis;
        inorder(root,preord);
        preordsort = preord;
        sort(preord.begin(),preord.end(),[](TreeNode* a, TreeNode* b) {return (a->val < b->val);});
        for(auto i: preord){
            vis[i->val]++;
            if(vis[i->val]>1) return false;
        }
        for(int i = 0;i<preord.size();i++){
            if(preord[i]!=preordsort[i]) return false;
        }
        return true;
    }

    void inorder(TreeNode* n,vector<TreeNode*> &ord){
        if(n==NULL) return;
        inorder(n->left,ord);
        ord.push_back(n);
        inorder(n->right,ord);
    }
    
};