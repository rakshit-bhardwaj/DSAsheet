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

    void deleteele(int val){
        if(head==NULL) return;
        while(head != NULL && head->data==val){
            head = head->next;
        }
        ListNode* ptr = head;
        while(ptr != NULL && ptr->next!=NULL){
            bool c = false;
            if(ptr->next->data == val){
                ptr->next = ptr->next->next;
                c = true;
            }
            if(!c) ptr = ptr->next;
        }
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
    int n = 4;
	cout << "Linked List Before deletion of "<<n<<endl;
	l.printList();
    l.deleteele(n);
	cout << "Linked List After deletion of "<<n<<endl;
	l.printList();

	return 0;
}
