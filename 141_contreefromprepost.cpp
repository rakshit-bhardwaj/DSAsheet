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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return con(preorder,postorder,0,preorder.size()-1,0,preorder.size()-1);
    }

    TreeNode* con(vector<int> pre,vector<int> post,int prsi,int prei,int posi,int poei){
        if(prsi > prei) return NULL;
        TreeNode* node = new TreeNode(pre[prsi]);
        if(prsi == prei) return node;

        int idx = posi;
        while(pre[prsi + 1] != post[idx]) idx++;

        int tot = idx - posi + 1;
        
        node->left = con(pre,post,prsi+1,prsi+tot,posi,idx);
        node->right = con(pre,post,prsi + tot+1,prei,idx + 1,poei - 1);
        
        return node;
    }
};