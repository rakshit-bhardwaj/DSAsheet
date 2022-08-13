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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode();
        ListNode *list3 = new ListNode();

        if (list1 == NULL && list2 == NULL)
            return NULL;

        if (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                head->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                head->val = list2->val;
                list2 = list2->next;
            }
            list3 = head;
        } else if(list1 != NULL && list2 == NULL){
            head->val = list1->val;
            list1=list1->next;
            list3 = head;
            goto onlylist1;
        }
        else{
            head->val = list2->val;
            list2=list2->next;
            list3 = head;
            goto onlylist2;
        }


        while (list1 != NULL && list2 != NULL)
        {
            ListNode *ptr = new ListNode();

            if (list1->val <= list2->val)
            {
                ptr->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                ptr->val = list2->val;
                list2 = list2->next;
            }

            list3->next = ptr;
            list3 = list3->next;
        }
        onlylist1:
        while (list1 != NULL)
        {
            ListNode *ptr = new ListNode();
            ptr->val = list1->val;
            list3->next = ptr;
            list3 = list3->next;

            list1 = list1->next;
        }
        onlylist2:
        while (list2 != NULL)
        {
            ListNode *ptr = new ListNode();
            ptr->val = list2->val;
            list3->next = ptr;
            list3 = list3->next;

            list2 = list2->next;
        }
        return head;
    }
};