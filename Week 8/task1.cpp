#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class List {

    Node* head;

public:

    List() {
        head = NULL;
    }

    void insertatend(int val) {

        Node* temp = new Node;

        temp->data = val;
        temp->next = NULL;
        temp->prev = NULL;

      
        if (head == NULL) {
            head = temp;
        }
        else {

            Node* curr = head;

            while (curr->next != NULL) {
                curr = curr->next;
            }

            curr->next = temp;
            temp->prev = curr;
        }
    }

    void display() {

        Node* curr = head;

        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    void insertatstart(int val) {

        Node* temp = new Node;

        temp->data = val;
        temp->prev = NULL;
        temp->next = head;

        if (head != NULL) {
            head->prev = temp;
        }

        head = temp;
    }

    void Nodeatpos(int val, int pos) {

        
        if (pos == 0) {
            insertatstart(val);
            return;
        }

        Node* temp = new Node;
        temp->data = val;

        Node* curr = head;

        for (int i = 0; i < pos - 1 && curr != NULL; i++) {
            curr = curr->next;
        }

      
        if (curr == NULL) {
            cout << "Invalid Position" << endl;
            return;
        }

        temp->next = curr->next;
        temp->prev = curr;

        if (curr->next != NULL) {
            curr->next->prev = temp;
        }

        curr->next = temp;
    }

    void reverse() {

        if (head == NULL) {
            return;
        }

        Node* curr = head;

     
        while (curr->next != NULL) {
            curr = curr->next;
        }

       
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->prev;
        }

        cout << endl;
    }
};

int main() {

    List l;

    l.insertatend(1);
    l.insertatend(2);
    l.insertatend(3);
    l.insertatend(4);

    cout << "Original List:" << endl;
    l.display();

    cout << "Insert at start:" << endl;
    l.insertatstart(5);
    l.display();

    cout << "Insert at specific position:" << endl;
    l.Nodeatpos(100, 2);
    l.display();

    cout << "Forward Traversal:" << endl;
    l.display();

    cout << "Reverse Traversal:" << endl;
    l.reverse();

    return 0;
}