#include <iostream>
using namespace std;

struct Student {
    string name;
    int priority; 
    Student* next;
};

class BookQueue {
private:
    string bookName;
    Student* head;

public:
    BookQueue(string name) {
        bookName = name;
        head = NULL;
    }

    void addStudent(string name, int priority) {
        Student* newNode = new Student{ name, priority, NULL };

        if (head == NULL || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Student* temp = head;
            while (temp->next != NULL && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << name << " added to " << bookName << endl;
    }

    
    void removeStudent(string name) {
        if (head == NULL) return;

        if (head->name == name) {
            Student* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Student* temp = head;
        while (temp->next != NULL && temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next != NULL) {
            Student* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }

    void updatePriority(string name, int newPriority) {
        removeStudent(name);
        addStudent(name, newPriority);
    }

   
    void serveStudent() {
        if (head == NULL) {
            cout << "No students waiting\n";
            return;
        }

        cout << "Serving: " << head->name << " for " << bookName << endl;

        Student* temp = head;
        head = head->next;
        delete temp;
    }

   
    void display() {
        cout << "\nBook: " << bookName << endl;

        if (head == NULL) {
            cout << "No reservations\n";
            return;
        }

        Student* temp = head;
        while (temp != NULL) {
            cout << temp->name << " (Priority: " << temp->priority << ")\n";
            temp = temp->next;
        }
    }

   
    int countStudents() {
        int count = 0;
        Student* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    BookQueue book1("Data Structures");
    BookQueue book2("Operating Systems");

   
    book1.addStudent("Ali", 2);
    book1.addStudent("Sara", 1);
    book1.addStudent("Ahmed", 3);

    book1.display();

    cout << "Total: " << book1.countStudents() << endl;

    book1.updatePriority("Ahmed", 1);
    book1.display();

    book1.serveStudent();
    book1.display();

    
    book2.addStudent("Zara", 2);
    book2.addStudent("Usman", 1);

    book2.display();

    return 0;
}