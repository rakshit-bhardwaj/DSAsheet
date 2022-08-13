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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> addresses;
        while(headA!=NULL){
            addresses[headA] = headA->val;
            headA=headA->next;
        }
        while(headB!=NULL){
            if(addresses.find(headB)!=addresses.end()) return headB;
            headB=headB->next;
        }
        return NULL;
    }
};