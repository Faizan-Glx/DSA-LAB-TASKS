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


	node* getParent(node* curr, node* prev, int num)
	{
		if (curr == NULL)
		{
			return NULL;
		}

		if (curr->data == num)
		{
			return prev;
		}
		else if (num < curr->data)
		{
			return getParent(curr->left, curr, num);
		}
		else
		{
			return getParent(curr->right, curr, num);
		}
	}

	node* findMin(node* curr)
	{
		while (curr != NULL && curr->left != NULL)
		{
			curr = curr->left;
		}

		return curr;
	}

	node* searchNode(node* root, int key) {

		if (root == NULL) {
			return NULL;
		}

		if (root->data == key) {
			return root;
		}

		if (key < root->data) {
			return searchNode(root->left, key);
		}

		if (key > root->data) {
			return searchNode(root->right, key);
		}



	}


	bool isIdentical(node* root1, node* root2)
	{
		// If both trees are empty
		if (root1 == NULL && root2 == NULL)
			return true;

		// If one is empty and the other is not
		if (root1 == NULL || root2 == NULL)
			return false;

		// Check data and recursively check left and right subtrees
		return (root1->data == root2->data) &&
			isIdentical(root1->left, root2->left) &&
			isIdentical(root1->right, root2->right);
	}


};


int main()
{
	BST tree1, tree2;

	int n1, n2, val;

	cout << "Enter number of nodes for Tree 1: ";
	cin >> n1;

	cout << "Enter values for Tree 1:\n";
	for (int i = 0; i < n1; i++)
	{
		cin >> val;
		tree1.root = tree1.insert(tree1.root, val);
	}

	cout << "\nEnter number of nodes for Tree 2: ";
	cin >> n2;

	cout << "Enter values for Tree 2:\n";
	for (int i = 0; i < n2; i++)
	{
		cin >> val;
		tree2.root = tree2.insert(tree2.root, val);
	}

	cout << "\nInorder Traversal of Tree 1: ";
	tree1.inorder(tree1.root);

	cout << "\nInorder Traversal of Tree 2: ";
	tree2.inorder(tree2.root);

	cout << endl;

	if (tree1.isIdentical(tree1.root, tree2.root))
	{
		cout << "\nBoth BSTs are IDENTICAL." << endl;
	}
	else
	{
		cout << "\nBoth BSTs are NOT IDENTICAL." << endl;
	}

	return 0;
}