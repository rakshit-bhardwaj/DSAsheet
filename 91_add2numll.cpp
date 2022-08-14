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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=new ListNode();
        ListNode* head=l3;
        int carry=0;
        l3->val = ( l1->val + l2->val ) %10;
        carry = ( l1->val + l2->val ) /10;
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL && l2!=NULL){
            ListNode* ptr = new ListNode();
            ptr->val = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            l1=l1->next;
            l2=l2->next;
            l3->next = ptr;
            l3 = l3->next;
        }
        while(l1!=NULL){
            ListNode* ptr = new ListNode();
            ptr->val = (l1->val + carry)%10;
            carry = (l1->val + carry)/10;
            l1=l1->next;
            l3->next = ptr;
            l3 = l3->next;
        }
        while(l2!=NULL){
            ListNode* ptr = new ListNode();
            ptr->val = (l2->val + carry)%10;
            carry = (l2->val + carry)/10;
            l2=l2->next;
            l3->next = ptr;
            l3 = l3->next;
        }
        if(carry){
            ListNode* ptr = new ListNode();
            ptr->val = carry;
            l3->next = ptr;
        }
        return head;
    }
};