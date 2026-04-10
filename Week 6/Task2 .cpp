#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class List {
    Node* head;

public:
    List() {
        head = NULL;
    }

    
    void insertAtEnd(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    }

  
    void insertAtBeginning(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void deleteByValue(int value) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

      
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->data != value) {
            prev = current;
            current = current->next;
        }

        
        if (current == NULL) {
            cout << "Value not found\n";
            return;
        }

        prev->next = current->next;
        delete current;
    }

   
    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {

    List obj;

    obj.insertAtEnd(5);
    obj.insertAtEnd(6);
    obj.insertAtEnd(7);

    obj.insertAtBeginning(1);

    cout << "List: ";
    obj.display();

    obj.deleteByValue(6);

    cout << "After deletion: ";
    obj.display();

    return 0;
}