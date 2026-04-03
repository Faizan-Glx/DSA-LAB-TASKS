#include <iostream>
using namespace std;

class TicketQueue {
private:
    int queue[100];
    int front;
    int rear;

public:
    TicketQueue() {
        front = -1;
        rear = -1;
    }

  
    void enqueue(int ticket_id) {
        if (rear == 99) {
            cout << "Queue Overflow! No space for new ticket.\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = ticket_id;

        cout << "Ticket " << ticket_id << " added successfully.\n";
    }

    
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "No tickets to resolve.\n";
            return;
        }

        cout << "Ticket " << queue[front] << " resolved.\n";
        front++;
    }

    void showFront() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Next ticket to resolve: " << queue[front] << endl;
    }

    
    void display() {
        if (front == -1 || front > rear) {
            cout << "No pending tickets.\n";
            return;
        }

        cout << "Pending Tickets: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TicketQueue q;
    int choice, id;

    do {
        cout << "\nCustomer Support Ticket System\n";
        cout << "1. Add Ticket\n";
        cout << "2. Resolve Ticket\n";
        cout << "3. View Next Ticket\n";
        cout << "4. Display All Tickets\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> id;
            q.enqueue(id);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.showFront();
            break;

        case 4:
            q.display();
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