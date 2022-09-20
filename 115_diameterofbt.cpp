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
    int height(TreeNode* n){
        if(n==NULL) return 0;
        return max(height(n->left),height(n->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = diameter(root);
        if(dia>0) dia -= 1;
        return dia;
    }
    int diameter(TreeNode* root) {
        if(root == NULL) return 0;
        int ld = diameter(root->left);
        int rd = diameter(root->right);
        int cur = height(root->left) + height(root->right) + 1;
        return max(cur,max(ld,rd));
    }
};