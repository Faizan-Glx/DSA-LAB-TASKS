#include<iostream>
using namespace std;

class Node {
public:

	int data;
	Node* next;


};

class List {
public:
	Node* head;

	List() {
		head = NULL;
	}

	void insertnode(int val) {

		Node* temp = new Node();
		temp->data = val;
		temp->next = NULL;

		if (head == NULL) {
			head = temp;
		}

		else {
			Node* curr = head;
			while (curr->next != NULL) {
				curr = curr->next;
			}

			curr->next = temp;


		}

	}

		void display(Node * curr) {
			

			
			if (curr == NULL) {
				return;
			}

			cout << curr->data << " ";

			display(curr->next);
		}
};


int main() {

	List l;
	l.insertnode(1);
	l.insertnode(2); 
	l.insertnode(3);
	l.insertnode(4);
	l.display(l.head);



	return 0;
}