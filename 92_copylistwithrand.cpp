#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        unordered_map<Node*,int> origlist;
        unordered_map<int,Node*> copylist;
        unordered_map<int,int> randmap;
        int ind = 1;
        Node* newhead = new Node(0);

        Node* ptr = newhead;
        Node* p = head;
        newhead->val = head->val;
        if(head->next == NULL){
            if(head->random == head){
                newhead->random = newhead;
            } else{
                newhead->random = NULL;
            }
            return newhead;
        }
        p=p->next;
        origlist[head] = 0;
        copylist[0] = newhead;
       
        while(p!=NULL){
            Node* n = new Node(0);
            n->val = p->val;
            ptr ->next = n;
            ptr = n;
            copylist[ind] = n;
            origlist[p] = ind;
            ind++;
            p=p->next;
        }
        // for(int i=0;i<ind;i++){
        //     cout<<i<<" -> "<<copylist[i]<<endl;
        // }
        // p = head;
        // while(p!=NULL){
        //     cout<<p<<" -> "<<origlist[p]<<endl;
        //     p=p->next;
        // }
        p = head;
        ind = 0;
        while(p!=NULL){
            if(p->random==NULL) randmap[ind] = -1;
            else randmap[ind] = origlist[p->random];
            p=p->next;
            ind++;
        }
        for(int i=0;i<ind;i++){
            cout<<i<<" -> "<<randmap[i]<<endl;
        }
        ptr = newhead;
        ind=0;
        while(ptr!=NULL){
            if(randmap[ind]==-1) ptr->random = NULL;
            else ptr->random = copylist[randmap[ind]];
            ptr=ptr->next;
            ind++;
        }
        return newhead;
    }
};