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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        int cur = 0;
        ListNode* ptr = head;
        ListNode* s,*e;
        ListNode* prev,*temp;
        if(head==NULL || head->next == NULL) return head;
        for(cur = 0;cur<left - 1;cur++){
            prev = ptr;
            ptr = ptr->next;
        }
        s = prev;
        ptr = ptr->next;
        e = ptr;
        while(ptr!=NULL && cur!=right){
            temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
            cur++;
        }
        if(s != NULL) s->next = prev;
        else head = prev;
        e->next = ptr;
        return head;
    }
};

// [1,2,3,4,5]
// 2
// 4