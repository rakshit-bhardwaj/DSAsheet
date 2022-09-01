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

    void splitevenodd(){
        if(this->head == NULL || this->head->next == NULL) return;
        ListNode* ptr = this->head;
        
        while(ptr!=NULL && ptr->next!=NULL){
            ptr = ptr->next;
        }
        ListNode* con = ptr;
        ListNode* ch = ptr;
        ptr = this->head;
        
        while(ptr->data%2!=0){
            ListNode* temp = ptr->next;
            ptr->next = NULL;
            con->next = ptr;
            con = con->next;
            ptr = temp;
        }
        this->head = ptr;
        ListNode* prev = ptr;
        ptr = ptr->next;
        
        while(ptr!= NULL && ptr!=ch){
            if(ptr->data%2!=0){
                prev->next = ptr->next;
                ptr->next = NULL;
                con->next = ptr;
                con = con->next;
                ptr = prev;
            }
            prev = ptr;
            ptr = ptr->next;
        }
    }
};

int main () {
    LinkedList l;
    l.push(17);
    l.push(15);
    l.push(8);
    l.push(12);
    l.push(10);
    l.push(5);
    l.push(4);
    l.push(1);
    l.push(7);
    l.push(6);
    l.printList();
    l.splitevenodd();
    l.printList();
    return 0;
}