#include <iostream>
#include <string>
using namespace std;

class PrintQueue {
private:
    string queue[100];
    int front;
    int rear;

public:
    PrintQueue() {
        front = -1;
        rear = -1;
    }


    void enqueue(string document_name) {
        if (rear == 99) {
            cout << "Print Queue is Full!\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = document_name;

        cout << "Document \"" << document_name << "\" added to print queue.\n";
    }

    
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "No documents to print.\n";
            return;
        }

        cout << "Printing document: " << queue[front] << endl;
        front++;
    }

    
    void showFront() {
        if (front == -1 || front > rear) {
            cout << "Print queue is empty.\n";
            return;
        }

        cout << "Next document to print: " << queue[front] << endl;
    }

    void display() {
        if (front == -1 || front > rear) {
            cout << "No pending print jobs.\n";
            return;
        }

        cout << "Documents in Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << endl;
        }
    }
};

int main() {

    PrintQueue printer;
    int choice;
    string doc;

    do {
        cout << "\nDocument Printing System\n";
        cout << "1. Add Print Job\n";
        cout << "2. Print Document\n";
        cout << "3. Check Next Document\n";
        cout << "4. Display Print Queue\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter document name: ";
            cin >> doc;
            printer.enqueue(doc);
            break;

        case 2:
            printer.dequeue();
            break;

        case 3:
            printer.showFront();
            break;

        case 4:
            printer.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}