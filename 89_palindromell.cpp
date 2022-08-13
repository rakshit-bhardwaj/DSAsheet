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
    bool isPalindrome(ListNode* head) {
        string num,rnum;
        while(head!=NULL){
            num.push_back(head->val + '0');
            head=head->next;
        }
        rnum = num;
        reverse(rnum.begin(),rnum.end());
        return rnum==num;
    }
};