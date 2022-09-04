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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* ptr = head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode *prev = dummy,*cur = dummy,*nex = dummy;
        int n = 0;
        while(ptr->next!=NULL){
            ptr = ptr->next;
            n++;
        }
        while(n>=k){
            cur = prev->next;
            nex = cur->next;
            for(int i =0;i<k-1;i++){
                cur->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex = cur->next;
            }
            prev = cur;
            n-=k;
        }
        return dummy->next;  
    }
};