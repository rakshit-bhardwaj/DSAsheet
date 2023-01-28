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

class Codec {
public:
    string ser;
    int si=0;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return ser;
        levelorder(root);
        cout<<"serialized -> "<<ser<<endl;
        return ser;
    }

    void levelorder(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i= 0;i<size;i++){
                TreeNode* n = q.front();
                q.pop();
                if(n==NULL){
                    ser.append("n,");
                    continue;
                }
                ser.append(to_string(n->val));
                ser.push_back(',');
                si = ser.size();
                q.push(n->left);
                q.push(n->right);
            }
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        vector<TreeNode*> nodes;
        int cur=0;
        bool neg = false;
        for(int i = 0;i<data.size();i++){
            
            if(data[i]==','){
                if(neg) {cur = cur * -1; neg = false;}
                TreeNode* t = new TreeNode(cur);
                nodes.push_back(t);
                cur = 0;
                continue;
            }
            if(data[i]=='n'){
                nodes.push_back(NULL);
                cur = 0;
                i++;
                continue;
            }
            if(data[i] == '-') {neg = true;continue;}
            cur = cur*10 + (data[i] - '0');
        }

        for(auto x : nodes) {if(x!=NULL) cout<<x->val<<" "; else cout<<"NULL"<<" ";}
        cout<<endl;

        int size = nodes.size();

        // for(int i = 0;i<size;i++){

        //     if(nodes[i]!=NULL){
        //         if(2*i + 1 <size){
        //             nodes[i]->left = nodes[2*i + 1];
        //         } if(2*i + 2 <size){
        //             nodes[i]->right = nodes[2*i + 2];
        //         }
        //     } 
        // }
        int count = 0;
        queue<TreeNode*> q;
        q.push(nodes[0]);
        TreeNode* curn = NULL;
        for(int i = 1;i<nodes.size();i++){
            if(count == 0) {
                curn = q.front();
                q.pop();
            }
            if(count == 0){
                count ++;
                curn->left = nodes[i];
            } else {
                count = 0;
                curn->right = nodes[i];
            } if (nodes[i]!= NULL){
                q.push(nodes[i]);
            }
        }
        
        return nodes[0];
    }
};