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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head->next==NULL){
            return head;
        }
        while(fast!=NULL){
            if(fast->next==NULL) break;
            fast = fast->next->next;
            slow = slow->next;   
        }
        return slow;
    }
};