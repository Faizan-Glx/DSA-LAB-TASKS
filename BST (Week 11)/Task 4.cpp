#include <iostream>
#include <string>
using namespace std;


class BSTNode {
public:
    int isbn;
    string title;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int id, string t) {
        isbn = id;
        title = t;
        left = right = NULL;
    }
};

class ListNode {
public:
    int isbn;
    string title;
    ListNode* next;

    ListNode(int id, string t) {
        isbn = id;
        title = t;
        next = NULL;
    }
};

class BST {
public:
    BSTNode* root;

    BST() {
        root = NULL;
    }

    
    BSTNode* insert(BSTNode* root, int isbn, string title) {
        if (root == NULL)
            return new BSTNode(isbn, title);

        if (isbn < root->isbn)
            root->left = insert(root->left, isbn, title);
        else if (isbn > root->isbn)
            root->right = insert(root->right, isbn, title);

        return root;
    }


    void inorder(BSTNode* root) {
        if (root != NULL) {
            inorder(root->left);
            cout << root->isbn << " - " << root->title << endl;
            inorder(root->right);
        }
    }

    
    void bstToList(BSTNode* root, ListNode*& head, ListNode*& tail) {
        if (root == NULL)
            return;

       
        bstToList(root->left, head, tail);

       
        ListNode* newNode = new ListNode(root->isbn, root->title);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }

      
        bstToList(root->right, head, tail);
    }
};


void printList(ListNode* head) {
    cout << "\nSorted Book Catalog (Linked List):\n";
    while (head != NULL) {
        cout << head->isbn << " - " << head->title << endl;
        head = head->next;
    }
}

int main() {
    BST library;

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int isbn;
        string title;

        cout << "\nEnter ISBN: ";
        cin >> isbn;

        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);

        library.root = library.insert(library.root, isbn, title);
    }

    cout << "\nBooks in BST (Inorder Traversal):\n";
    library.inorder(library.root);


    ListNode* head = NULL;
    ListNode* tail = NULL;

    library.bstToList(library.root, head, tail);


    printList(head);

    return 0;
}