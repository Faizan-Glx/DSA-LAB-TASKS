#include<iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T> {
    T* arr;
    int rear;
    int frontIndex;
    int size;

public:
    myQueue(int s) {
        size = s;
        rear = -1;
        frontIndex = -1;
        arr = new T[size];
    }

    bool isEmpty() const {
        return frontIndex == -1;
    }

    bool isFull() const {
        return rear == size - 1;
    }

    void enQueue(T value) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }

        if (frontIndex == -1) {
            frontIndex = 0;
        }

        rear++;
        arr[rear] = value;
    }

    T deQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return T(); 
        }

        T value = arr[frontIndex];
        frontIndex++;

       
        if (frontIndex > rear) {
            frontIndex = rear = -1;
        }

        return value;
    }

    T front() const {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return T();
        }
        return arr[frontIndex];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = frontIndex; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~myQueue() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;

    myQueue<int> q(size);

    int choice, value;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            cout << "Dequeued: " << q.deQueue() << endl;
            break;

        case 3:
            cout << "Front: " << q.front() << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
