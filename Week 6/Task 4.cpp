#include <iostream>
using namespace std;

struct Patient {
    int id;
    string name;
    Patient* next;
};

class HospitalQueue {
private:
    Patient* head;

public:
    HospitalQueue() {
        head = NULL;
    }

 
    void addPatient(int id, string name) {
        Patient* newNode = new Patient{ id, name, NULL };

        if (head == NULL) {
            head = newNode;
        }
        else {
            Patient* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Patient added: " << name << endl;
    }

    
    void removePatient(int id) {
        if (head == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        if (head->id == id) {
            Patient* temp = head;
            head = head->next;
            delete temp;
            cout << "Patient removed\n";
            return;
        }

        Patient* temp = head;
        while (temp->next != NULL && temp->next->id != id) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Patient not found\n";
        }
        else {
            Patient* del = temp->next;
            temp->next = del->next;
            delete del;
            cout << "Patient removed\n";
        }
    }

    
    void display() {
        if (head == NULL) {
            cout << "No patients in queue\n";
            return;
        }

        Patient* temp = head;
        while (temp != NULL) {
            cout << temp->id << " - " << temp->name << endl;
            temp = temp->next;
        }
    }

    int countPatients() {
        int count = 0;
        Patient* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    HospitalQueue hq;

    hq.addPatient(1, "Ali");
    hq.addPatient(2, "Ahmed");
    hq.addPatient(3, "Sara");

    cout << "\nPatient List:\n";
    hq.display();

    cout << "\nTotal Patients: " << hq.countPatients() << endl;

    hq.removePatient(2);

    cout << "\nAfter Removal:\n";
    hq.display();

    return 0;
}