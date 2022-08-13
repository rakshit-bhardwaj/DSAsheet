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

    ListNode* node(int val){
        if(head==NULL) return NULL;
        ListNode* ptr = head;
        while(ptr!=NULL){
            if(ptr->data==val){
                return ptr;
            }
            ptr = ptr->next;
        }
        return NULL;
    }

    void deletenode(ListNode* node){
        if(node==NULL || node->next==NULL) return;
        while(node->next->next!=NULL){
            node->data = node->next->data;
            node = node->next;
        }
        node->data = node->next->data;
        node->next=NULL;
    }

};

int main(void)
{
	LinkedList l;
	l.push(8);
	l.push(6);
	l.push(2);
	l.push(3);
	l.push(2);
	l.push(4);
	l.push(0);
	l.push(4);
    int n = 8;
    ListNode* ptr = l.node(n);
	cout << "Linked List Before deletion of "<<ptr<<endl;
	l.printList();
    l.deletenode(ptr);
	cout << "Linked List After deletion of "<<ptr<<endl;
	l.printList();

	return 0;
}
