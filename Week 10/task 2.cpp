#include<iostream>
#include<string>
using namespace std;

class Node {
public:
    int songID;
    string songName;
    float duration;

    Node* next;
    Node* prev;

    Node(int id, string name, float dur) {
        songID = id;
        songName = name;
        duration = dur;
        next = NULL;
        prev = NULL;
    }
};

class Playlist {
    Node* head;
    Node* tail;
    Node* current;

public:

    Playlist() {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    void addSong(int id, string name, float dur) {

        Node* temp = new Node(id, name, dur);

        if (head == NULL) {
            head = tail = current = temp;
        }
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        cout << "Song Added Successfully" << endl;
    }

    void displayPlaylist() {

        if (head == NULL) {
            cout << "Playlist is Empty" << endl;
            return;
        }

        Node* curr = head;

        cout << "\nPlaylist:\n";

        while (curr != NULL) {

            cout << "Song ID: " << curr->songID << endl;
            cout << "Song Name: " << curr->songName << endl;
            cout << "Duration: " << curr->duration << " minutes" << endl;
            cout << "----------------------" << endl;

            curr = curr->next;
        }
    }

    void deleteSong(string name) {

        if (head == NULL) {
            cout << "Playlist is Empty" << endl;
            return;
        }

        Node* curr = head;

        while (curr != NULL && curr->songName != name) {
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Song Not Found" << endl;
            return;
        }

        if (curr == head && curr == tail) {
            head = tail = NULL;
        }
        else if (curr == head) {
            head = head->next;
            head->prev = NULL;
        }
        else if (curr == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }
        else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        if (current == curr) {
            current = head;
        }

        delete curr;

        cout << "Song Deleted Successfully" << endl;
    }

    void playCurrent() {

        if (current == NULL) {
            cout << "No Song Available" << endl;
            return;
        }

        cout << "\nNow Playing:\n";
        cout << current->songName << " (" << current->duration << " min)" << endl;
    }

    void playNext() {

        if (current == NULL) {
            cout << "Playlist is Empty" << endl;
            return;
        }

        if (current->next == NULL) {
            cout << "No Next Song" << endl;
            return;
        }

        current = current->next;

        playCurrent();
    }

    void playPrevious() {

        if (current == NULL) {
            cout << "Playlist is Empty" << endl;
            return;
        }

        if (current->prev == NULL) {
            cout << "No Previous Song" << endl;
            return;
        }

        current = current->prev;

        playCurrent();
    }

    void reversePlaylist() {

        Node* curr = head;
        Node* temp = NULL;

        while (curr != NULL) {

            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            curr = curr->prev;
        }

        temp = head;
        head = tail;
        tail = temp;

        current = head;

        cout << "Playlist Reversed Successfully" << endl;
    }
};

int main() {

    Playlist p;

    p.addSong(1, "Shape of You", 4.2);
    p.addSong(2, "Believer", 3.8);
    p.addSong(3, "Perfect", 4.5);
    p.addSong(4, "Faded", 3.4);

    p.displayPlaylist();

    p.playCurrent();

    p.playNext();

    p.playNext();

    p.playPrevious();

    p.deleteSong("Perfect");

    p.displayPlaylist();

    p.reversePlaylist();

    p.displayPlaylist();

    return 0;
}