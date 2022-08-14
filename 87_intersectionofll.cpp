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
        int c=0,c1=0,c2=0;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(p1!=NULL){
            c1++;
            p1=p1->next;
        }
        while(p2!=NULL){
            c2++;
            p2=p2->next;
        }
        p1 = headA;
        p2 = headB;
        c = abs(c1-c2);
        if(c1>c2){
            for(int i=0;i<c;i++){
                p1 = p1->next;
            }
        } else if(c2>c1) {
            for(int i=0;i<c;i++){
                p2 = p2->next;
            }
        }
        while(p1!=NULL && p2!=NULL){
            if(p1==p2) return p1;
            p1=p1->next;
            p2=p2->next;
        }
        return NULL;
    }
};
