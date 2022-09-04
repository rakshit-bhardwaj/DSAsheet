#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
	int data=0;
	ListNode *next=NULL;
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

    void reversell(){
        ListNode* prev =NULL;
        ListNode* cur = this->head;
        ListNode* temp;
        while(cur!=NULL){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        this->head = prev;
    }

    ListNode subtractll(LinkedList l1,LinkedList l2){
        ListNode* n1 = l1.head;
        ListNode* n2 = l2.head;
        int s1 = 0,s2 = 0;
        while(n1!=NULL){
            n1 = n1->next;
            s1++;
        }
        while(n2!=NULL){
            n2 = n2->next;
            s2++;
        }
        int gl;
        if(s1<s2){
            gl = 2;
            while(s1<s2){
                ListNode *temp = new ListNode();
                temp->data = 0;
                temp->next = l1.head;
                l1.head = temp;
                s1++;
            }
        } else if(s2<s1){
            gl = 1;
            while(s2<s1){
                ListNode *temp = new ListNode();
                temp->data = 0;
                temp->next = l2.head;
                l2.head = temp;
                s2++;
            }
        } else {
            n1 = l1.head;
            n2 = l2.head;
            while(n1!=NULL){
                if(n1->data > n2->data){
                    gl = 1;
                    break;
                } else if(n1->data < n2->data){
                    gl = 2;
                    break;
                }
                n1 = n1->next;
                n2 = n2->next;
            }
            if(n1==NULL){
                cout<<"0"<<endl;
                exit(0);
            }
        }
    

        l1.reversell();l2.reversell();
        if(gl==2){
            n1 = l2.head;
            n2 = l1.head;
        } else {
            n1 = l1.head;
            n2 = l2.head;
        }
        
        LinkedList l3;
        ListNode* n3 = new ListNode();
        ListNode* newhead = n3;
        int borrow = 0;
        while(n1!=NULL){
            ListNode* n = new ListNode();
            int sub;
            if(n1->data - borrow >= n2->data){
                sub = n1->data - n2->data - borrow;
                borrow = 0;
            } else{
                sub = n1->data + 10 - n2->data - borrow;
                borrow = 1;
            }
            n1 = n1->next; n2 = n2->next;
            n->data = sub;
            n3->next = n;
            n3 = n3->next;
        }
        l3.head = newhead->next;
        l3.reversell();
        l3.printList();
    }
};

int main () {
    LinkedList n1,n2;
    n1.push(1);
    n1.push(0);
    n1.push(0);
    n2.push(1);
    n2.push(1);
    n2.push(1);
    cout<<"num1 => ";
    n1.printList();
    cout<<"num2 => ";
    n2.printList();
    n1.subtractll(n1,n2);
    return 0;
}