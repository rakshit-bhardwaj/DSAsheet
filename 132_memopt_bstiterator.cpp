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

class BSTIterator {
public:
    stack<TreeNode*> cache;
    int size=0;

    BSTIterator(TreeNode* root) {
        while(root!=NULL){
            cache.push(root);
            root = root->left;
            size++;
        }
    }
    
    int next() {
        TreeNode* ans = cache.top();
        cache.pop();size--;
        TreeNode* cur = ans->right;
        while(cur!=NULL){
            cache.push(cur);
            cur = cur->left;
            size++;
        }
        return ans->val;
    }
    
    bool hasNext() {
        return size>0;
    }
};