#include<iostream>
using namespace std;

class Node {
public:
    int playerID;
    int score;

    Node* next;

    Node(int id, int s) {
        playerID = id;
        score = s;
        next = NULL;
    }
};

class Game {
    Node* head;
    Node* current;

public:

    Game() {
        head = NULL;
        current = NULL;
    }

    void addPlayer(int id, int score) {

        Node* temp = new Node(id, score);

        if (head == NULL) {
            head = temp;
            temp->next = head;
            current = head;
        }
        else {

            Node* curr = head;

            while (curr->next != head) {
                curr = curr->next;
            }

            curr->next = temp;
            temp->next = head;
        }

        cout << "Player Added Successfully" << endl;
    }

    void displayPlayers() {

        if (head == NULL) {
            cout << "No Players in Game" << endl;
            return;
        }

        Node* curr = head;

        cout << "\nPlayers in Game:\n";

        do {
            cout << "Player ID: " << curr->playerID << endl;
            cout << "Score: " << curr->score << endl;
            cout << "-------------------" << endl;

            curr = curr->next;

        } while (curr != head);
    }

    void nextTurn() {

        if (current == NULL) {
            cout << "No Players Available" << endl;
            return;
        }

        cout << "\nCurrent Turn -> Player " << current->playerID << endl;

        current = current->next;
    }

    void skipPlayer() {

        if (current == NULL) {
            cout << "No Players Available" << endl;
            return;
        }

        cout << "\nPlayer " << current->playerID << " is skipped" << endl;

        current = current->next;

        cout << "Next Turn -> Player " << current->playerID << endl;

        current = current->next;
    }

    void removePlayer(int id) {

        if (head == NULL) {
            cout << "No Players in Game" << endl;
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        if (head->playerID == id && head->next == head) {

            cout << "Player " << head->playerID << " Removed" << endl;

            delete head;

            head = NULL;
            current = NULL;

            return;
        }

        do {

            if (curr->playerID == id) {
                break;
            }

            prev = curr;
            curr = curr->next;

        } while (curr != head);

        if (curr->playerID != id) {
            cout << "Player Not Found" << endl;
            return;
        }

        if (curr == head) {

            Node* last = head;

            while (last->next != head) {
                last = last->next;
            }

            head = head->next;
            last->next = head;
        }
        else {
            prev->next = curr->next;
        }

        if (current == curr) {
            current = curr->next;
        }

        cout << "Player " << curr->playerID << " Removed" << endl;

        delete curr;
    }

    void checkWinner() {

        if (head != NULL && head->next == head) {

            cout << "\nGame Over" << endl;
            cout << "Winner is Player " << head->playerID << endl;
        }
    }
};

int main() {

    Game g;

    g.addPlayer(1, 50);
    g.addPlayer(2, 70);
    g.addPlayer(3, 40);
    g.addPlayer(4, 90);

    g.displayPlayers();

    g.nextTurn();
    g.nextTurn();

    g.skipPlayer();

    g.removePlayer(3);

    g.displayPlayers();

    g.removePlayer(2);
    g.removePlayer(4);

    g.displayPlayers();

    g.checkWinner();

    return 0;
}