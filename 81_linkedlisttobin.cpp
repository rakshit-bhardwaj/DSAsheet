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
    int getDecimalValue(ListNode* head) {
        int val=0;
        if(head==NULL) return 0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            val = val*2 + ptr->val;
            ptr=ptr->next;
        }
        return val;
    }
};