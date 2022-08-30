#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next == NULL) return;
        vector<ListNode*> add;
        int s = 1,e=0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            ListNode* n = ptr->next;
            ptr ->next = NULL;
            add.push_back(ptr);
            ptr = n;
            e++;
        }
        e--;
        int n = e+1;
        ptr = head;
        for(auto it : add){
            cout<<it->val<<" ";
        }
        cout<<endl;
        while(ptr!=NULL && e>=s){
            cout<<"itr ";
            ptr -> next = add[e];
            ptr = ptr->next;
            if(e==s) break;
            e--;
            ptr ->next = add[s];
            ptr = ptr->next;
            s++;
        }
        cout<<"flag\n";
        cout<<endl;
        ptr = head;
        while(ptr!=NULL){
            cout<<ptr->val;
            if(ptr->next!=NULL)
            cout<<" -> ";
            ptr = ptr->next;
        }
        cout<<"\nflag2";
    }
};