#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    vector<Node*> nodes;
    void dfs(Node* n){
        Node* temp = n->child;
        n->child = NULL;
        nodes.push_back(n);
        if(temp!=NULL) dfs(temp);
        if(n->next != NULL) dfs(n->next);
        else return;
    }
    Node* flatten(Node* head) {
        if(head == NULL || (head->next == NULL && head->child == NULL)) return head;
        dfs(head);
        for(int i=0;i<nodes.size()-1;i++){
            nodes[i]->next = nodes[i+1];
        }
        for(int i=nodes.size()-1;i>0;i--){
            nodes[i]->prev = nodes[i-1];
        }
        return head;
    }
};
