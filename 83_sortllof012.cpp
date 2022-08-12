#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
};

class LinkedList
{
public:
	Node *head = NULL;

	void push(int data)
	{
		Node *ptr = new Node();
		ptr->data = data;
		if (head == NULL)
		{
			head = ptr;
		}
		else
		{
			Node *temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = ptr;
		}
	}

	void printList()
	{
		Node *ptr = head;
		while (ptr->next != NULL)
		{   
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
	void sortList()
	{
		map<int, int> count;
		Node *ptr = head;
		if (head == NULL || head->next == NULL)
			return;
		while (ptr->next != NULL)
		{
			count[ptr->data]++;
			ptr = ptr->next;
		}
		cout << "count of 0 -> " << count[0] << " count of 1 -> " << count[1] << " count of 2 -> " << count[2] << endl;
		ptr = head;
		while (ptr->next != NULL)
		{
			if (count[0] > 0)
			{
				count[0]--;
				ptr->data = 0;
			}
			else if (count[1] > 0)
			{
				count[1]--;
				ptr->data = 1;
			}
			else
			{
				count[2]--;
				ptr->data = 2;
			}
			ptr = ptr->next;
		}
	}
};

int main(void)
{
	LinkedList l;
	l.push(0);
	l.push(2);
	l.push(2);
	l.push(1);
	l.push(2);
	l.push(1);
	l.push(0);
	l.push(1);

	cout << "Linked List Before Sorting\n";
	l.printList();
	l.sortList();
	cout << "Linked List After Sorting\n";
	l.printList();

	return 0;
}
