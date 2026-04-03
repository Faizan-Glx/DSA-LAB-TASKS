#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front;
    int rear;

public:

    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int x) {
        if (rear == 99) {
            cout << "Queue Full\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }

        return arr[front++];
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }

        return arr[front];
    }

    int size() {
        if (isEmpty())
            return 0;
        return rear - front + 1;
    }

    void display() {
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void reverseFirstK(int k) {

        int n = size();

        if (k <= 1 || k > n)
            return;

        int stack[100];
        int top = -1;

        
        for (int i = 0; i < k; i++) {
            stack[++top] = dequeue();
        }

        
        while (top != -1) {
            enqueue(stack[top--]);
        }

        
        int remaining = n - k;

        for (int i = 0; i < remaining; i++) {
            enqueue(dequeue());
        }
    }
};

int main() {

    Queue q;
    int n, x, k;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter queue elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    cout << "Queue: ";
    q.display();

    cout << "Enter K: ";
    cin >> k;

    q.reverseFirstK(k);

    cout << "Output: ";
    q.display();

    return 0;
}