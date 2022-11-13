#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left, *right;
};

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    vector<Node*> preorder;
    pre = NULL;suc = NULL;
    findpreorder(root,preorder);
    cout<<"preorder -> ";
    for(auto n: preorder) cout<<n->key<<" ";
    cout<<endl;
    if(key<=preorder[0]->key){
        suc = (key == preorder[0]->key && preorder.size() > 1) ? preorder[1] : preorder[0];
        return;
    } 
    if(key>=preorder[preorder.size()-1]->key){
        pre = (key == preorder[preorder.size()-1]->key && preorder.size() > 1) ? preorder[preorder.size()-2] : preorder[preorder.size()-1];
        return;
    }
    
    for(int i = 1;i<preorder.size();i++){
        
        if(preorder[i]->key>=key){
            pre = preorder[i-1];
            suc = preorder[i]->key==key ? preorder[i+1] : preorder[i];
            return;
        }
    }
}

void findpreorder(Node* root,vector<Node*> &preorder){
    if(root==NULL) return;
    findpreorder(root->left,preorder);
    preorder.push_back(root);
    findpreorder(root->right);
}

