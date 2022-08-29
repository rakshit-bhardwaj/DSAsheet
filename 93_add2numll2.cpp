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
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = head,*prev = NULL,*temp;
        if(head==NULL || head->next==NULL) return head;
        while(ptr!=NULL){
            temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        ListNode* l3 = new ListNode();
        ListNode* h3 = NULL;
        ListNode* ptr = l1;
        while(ptr!=NULL){
            s1.push(ptr->val);
            ptr=ptr->next;
        }
        ptr = l2;
        while(ptr!=NULL){
            s2.push(ptr->val);
            ptr=ptr->next;
        }
        // cout<<"stack 1 stack 2\n";
        // stack<int> ss1 = s1,ss2 = s2;
        // while(!ss1.empty() && !ss2.empty()){
        //     cout<<ss1.top()<<"    "<<ss2.top()<<endl;
        //     ss1.pop();ss2.pop();
        // }
        int carry = 0;
        while(!s1.empty() && !s2.empty()){
            ListNode* n = new ListNode();
            n->val = (s1.top() + s2.top() + carry)%10;
            carry = (s1.top() + s2.top() + carry)/10;
            s1.pop();s2.pop();
            if(h3==NULL){
                h3 = n;
                l3 = n;
            }
            else {
                l3->next = n;
                l3 = l3->next;
            }  
        }
        while(!s1.empty()){
            ListNode* n = new ListNode();
            n->val = (s1.top() + carry)%10;
            carry = (s1.top() + carry)/10;
            s1.pop();
            if(h3==NULL){
                h3 = n;
                l3 = n;
            }
            else {
                l3->next = n;
                l3 = l3->next;
            }
        }
        while(!s2.empty()){
            ListNode* n = new ListNode();
            n->val = (s2.top() + carry)%10;
            carry = (s2.top() + carry)/10;
            s2.pop();
            if(h3==NULL){
                h3 = n;
                l3 = n;
            }
            else {
                l3->next = n;
                l3 = l3->next;
            }
        }
        while(carry>0){
            ListNode* n = new ListNode();
            n->val = carry%10;
            carry = carry/10;  
            l3->next = n;
            l3 = l3->next;
        }
        return reverseList(h3);
    }
};