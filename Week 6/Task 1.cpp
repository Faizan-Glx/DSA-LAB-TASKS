//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//    int data;
//    Node* next;
//};
//
//class List {
//    Node* head;
//
//public:
//    List() {
//        head = NULL;
//    }
//
//    void createnode(int value) {
//        Node* temp = new Node;
//        temp->data = value;
//        temp->next = NULL;
//
//        if (head == NULL) {
//            head = temp;
//        }
//        else {
//            Node* current = head;
//            while (current->next != NULL) {
//                current = current->next;
//            }
//            current->next = temp;
//        }
//    }
//
//    void display() {
//        Node* temp = head;
//
//        while (temp != NULL) {
//            cout << temp->data << endl;
//            temp = temp->next;
//        }
//    }
//};
//
//int main() {
//
//    List obj;
//    obj.createnode(5);
//    obj.createnode(6);
//    obj.display();
//
//    return 0;
//}