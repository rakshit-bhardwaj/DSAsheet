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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* f=head,*s=head;
        if(head->next==NULL) return NULL;
        int i = n;
        while(n--){
            f=f->next;
        }
        if(f==NULL) return head->next;
        while(f!=NULL && f->next!=NULL){
            f=f->next;
            s=s->next;
        }
        s->next = s->next->next;
        return head;
    }
};