#include <iostream>
using namespace std;

class Queue {
private:
    int s1[100], s2[100];
    int top1, top2;

public:

    Queue() {
        top1 = -1;
        top2 = -1;
    }

    bool isEmpty() {
        return (top1 == -1 && top2 == -1);
    }

 
    void enqueue(int x) {
        if (top1 == 99) {
            cout << "Queue Overflow\n";
            return;
        }

        s1[++top1] = x;
        cout << x << " inserted into queue\n";
    }

 
    void transfer() {
        while (top1 != -1) {
            s2[++top2] = s1[top1--];
        }
    }

    void dequeue() {

        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }

        if (top2 == -1)
            transfer();

        cout << "Removed: " << s2[top2--] << endl;
    }


    void front() {

        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }

        if (top2 == -1)
            transfer();

        cout << "Front Element: " << s2[top2] << endl;
    }

    void display() {

        if (isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Queue Elements: ";

        
        for (int i = top2; i >= 0; i--)
            cout << s2[i] << " ";

       
        for (int i = 0; i <= top1; i++)
            cout << s1[i] << " ";

        cout << endl;
    }
};

int main() {

    Queue q;
    int choice, x;

    do {

        cout << "\nQueue using Two Stacks\n";
        cout << "1 Enqueue\n";
        cout << "2 Dequeue\n";
        cout << "3 Front\n";
        cout << "4 Display\n";
        cout << "5 Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter element: ";
            cin >> x;
            q.enqueue(x);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.front();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}