#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* ptr = head;
        while(ptr!=NULL && ptr->next!=NULL){
            if(ptr->next->val == ptr->val){
                ListNode* temp = ptr->next;
                while(temp->next != NULL && temp->val==ptr->val){
                    temp=temp->next;
                }
                if(temp->val==ptr->val){
                    ptr->next = NULL;
                } else {
                    ptr->next = temp;
                }
            }
            ptr=ptr->next;
        }
        return head;
    }
};
