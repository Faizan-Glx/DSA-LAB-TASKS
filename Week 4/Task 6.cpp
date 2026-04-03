#include <iostream>
#include <string>
using namespace std;

class PackageQueue {
private:

    struct Package {
        int id;
        string address;
        int startTime;
        int endTime;
    };

    Package queue[100];
    int front;
    int rear;

public:

    PackageQueue() {
        front = -1;
        rear = -1;
    }

   
    void enqueue(int id, string address, int start, int end) {

        if (rear == 99) {
            cout << "Queue Full!\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear++;

        queue[rear].id = id;
        queue[rear].address = address;
        queue[rear].startTime = start;
        queue[rear].endTime = end;

        cout << "Package " << id << " added successfully.\n";
    }

  
    void dequeue() {

        if (front == -1 || front > rear) {
            cout << "No packages to deliver.\n";
            return;
        }

        cout << "Package Delivered\n";
        cout << "ID: " << queue[front].id << endl;
        cout << "Address: " << queue[front].address << endl;

        front++;
    }

   
    void showFront() {

        if (front == -1 || front > rear) {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Next Package:\n";
        cout << "ID: " << queue[front].id << endl;
        cout << "Address: " << queue[front].address << endl;
        cout << "Time Window: " << queue[front].startTime
            << " - " << queue[front].endTime << endl;
    }

  
    void timeToDeliver(int currentTime) {

        if (front == -1 || front > rear) {
            cout << "No packages in queue.\n";
            return;
        }

        if (currentTime >= queue[front].startTime &&
            currentTime <= queue[front].endTime) {

            cout << "Package can be delivered now.\n";
        }
        else {

            cout << "Delivery window expired for Package "
                << queue[front].id << endl;

            front++; 
        }
    }

 
    void display() {

        if (front == -1 || front > rear) {
            cout << "No packages in queue.\n";
            return;
        }

        cout << "\nPackages in Queue:\n";

        for (int i = front; i <= rear; i++) {

            cout << "ID: " << queue[i].id << endl;
            cout << "Address: " << queue[i].address << endl;
            cout << "Time Window: "
                << queue[i].startTime << " - "
                << queue[i].endTime << endl;

            cout << "------------------\n";
        }
    }
};

int main() {

    PackageQueue pq;

    int choice;
    int id, start, end, time;
    string address;

    do {

        cout << "\nReal-Time Package Delivery System\n";
        cout << "1 Add Package\n";
        cout << "2 Deliver Package\n";
        cout << "3 Check Front Package\n";
        cout << "4 Check Time To Deliver\n";
        cout << "5 Display Packages\n";
        cout << "6 Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Package ID: ";
            cin >> id;

            cout << "Enter Address: ";
            cin >> address;

            cout << "Enter Start Time: ";
            cin >> start;

            cout << "Enter End Time: ";
            cin >> end;

            pq.enqueue(id, address, start, end);
            break;

        case 2:
            pq.dequeue();
            break;

        case 3:
            pq.showFront();
            break;

        case 4:
            cout << "Enter Current Time: ";
            cin >> time;
            pq.timeToDeliver(time);
            break;

        case 5:
            pq.display();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}