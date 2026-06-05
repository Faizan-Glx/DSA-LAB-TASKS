#include<iostream>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;


};

class BST {
public:
	node* root;

	BST() {
		root = NULL;
	}

	node* create(int val) {
		node* newnode = new node;
		newnode->data = val;
		newnode->left = NULL;
		newnode->right = NULL;

		return newnode;
	}

	node* insert(node* root, int val) {

		if (root == NULL) {
			return create(val);
		}

		if (val < root->data) {
			root->left = insert(root->left, val);
		}

		if (val > root->data) {
			root->right = insert(root->right, val);
		}

		return root;

	}


	void inorder(node* root) {

		if (root != NULL) {
			 inorder(root->left);
			cout << root->data << " ";
			inorder(root->right);
		}

	}

	void preorder(node* root) {
		if (root != NULL) {
			cout << root->data << " ";
			preorder(root->left);
			preorder(root->right);
			


		}
	}

	void postorder(node* root) {

		if (root != NULL) {
			postorder(root->left);
			postorder(root->right);
			cout << root->data << " ";
		}
	}

	node* find(node* root, int key) {

		if (root == NULL) {
			return NULL;
		}

		if (root->data == key) {
			return root;
		}

		if (key < root->data) {
			return find(root->left, key);
		}

		if (key > root->data) {
			return find(root->right, key);
		}



	}


};


int main() {

	BST obj;
	int val=0;
	int n;
	cout << "Entre number of roots: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Entre number: ";
		cin >> val;
		obj.root=obj.insert(obj.root, val);
	}

	cout << "Inorder" << endl;
	obj.inorder(obj.root);
	cout << endl;
	cout << "Preorder" << endl;
	obj.preorder(obj.root);
	cout << endl;
	cout << "Postorder" << endl;
	obj.postorder(obj.root);

	cout << endl;
	int search = 0;
	cout << "Entre a number to search: ";
	cin >> search;
	

	node * result=obj.find(obj.root,search);
	if (result != NULL) {
		cout << search << " found in BST." << endl;
	}
	else {
		cout << search << " not found in BST." << endl;
	}



	return 0;
}