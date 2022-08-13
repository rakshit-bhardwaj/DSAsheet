#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
	int data;
	ListNode *next;
};

class LinkedList
{
public:
	ListNode *head = NULL;

	void push(int data)
	{
		ListNode *ptr = new ListNode();
		ptr->data = data;
		if (head == NULL)
		{
			head = ptr;
		}
		else
		{
			ListNode *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = ptr;
		}
	}

	void printList()
	{
		ListNode *ptr = head;
		while (ptr != NULL)
		{   
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
    int multiplyll(ListNode* l1,ListNode* l2){
        int n1=0,n2=0;
        while(l1!=NULL){
            n1 = n1*10 + l1->data;
            l1=l1->next;
        }
        while(l2!=NULL){
            n2 = n2*10 + l2->data;
            l2=l2->next;
        }
        return n1*n2;
    }
};

int main(void)
{
	LinkedList l1,l2;
	l1.push(3);
	l1.push(2);
	l1.push(1);
	l2.push(1);
	l2.push(2);
    cout<<"list 1 -> ";
    l1.printList();
    cout<<"list 2 -> ";
    l2.printList();
    cout<<l1.multiplyll(l1.head,l2.head);
	return 0;
}
