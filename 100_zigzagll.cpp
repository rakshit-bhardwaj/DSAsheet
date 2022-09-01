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

    void zigzag(ListNode* n,bool flag){
        if(n==NULL || n->next == NULL) return;
        if(flag){
            if(n->data > n->next->data){
                swap(n->data,n->next->data);
            }
        } else {
            if(n->data < n->next->data){
                swap(n->data,n->next->data);
            }
        }
        zigzag(n->next,!flag);
    }

};

int main () {
    LinkedList l;
    l.push(11);
    l.push(15);
    l.push(20);
    l.push(5);
    l.push(10);
    l.printList();
    l.zigzag(l.head,1);
    l.printList();
    return 0;
}