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
    ListNode* deletedup(ListNode* head,ListNode* n){
        if(head == n){
            while(n!=NULL && n->val == head->val){
                n=n->next;
            }
            return n;
        }
        ListNode *ptr = head;
        while(ptr!=NULL){
            if(ptr->next != NULL && ptr->next->val == n->val){
                ListNode* temp = ptr->next;
                while(temp!=NULL && temp->val == n->val){
                    temp = temp->next;
                }
                ptr->next = temp;
                break;
            }
            ptr=ptr->next;
        }
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* ptr = head;
        map<int,int> freq;
        while(ptr!=NULL){
            freq[ptr->val]++;
            cout<<"frequency of "<<ptr->val<<" = "<<freq[ptr->val]<<endl;
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr!=NULL){
            if(freq[ptr->val]>1){
                cout<<"deleting "<<ptr->val<<endl;
                head = deletedup(head,ptr);
            }
            ptr = ptr->next;
        }
        return head;
    }
};

//1 2 3 3 4 4 5
