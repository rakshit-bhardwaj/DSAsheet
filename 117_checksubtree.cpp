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
    bool sametree(TreeNode* n1,TreeNode* n2){
        if(n1 == NULL && n2 == NULL) return true;
        if(n1!=NULL && n2!=NULL && n1->val == n2->val)
        return sametree(n1->left,n2->left) && sametree(n1->right,n2->right);
        return false;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot == NULL) return true;
        if(root == NULL) return false;
        if(sametree(root,subRoot)) return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);

    }
};