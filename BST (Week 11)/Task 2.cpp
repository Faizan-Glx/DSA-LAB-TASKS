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
        

	node* deleteNode(node* curr, int value)
	{

		if (curr == NULL)
		{
			return NULL;
		}

		// Move left if val is less than root
		if (value < curr->data)
		{
			curr->left = deleteNode(curr->left, value);
		}

		// Move right if it is greater than root
		else if (value > curr->data)
		{
			curr->right = deleteNode(curr->right, value);
		}


		else
		{
			//  No child  yani right left dono null ha
			if (curr->left == NULL && curr->right == NULL)
			{
				delete curr;
				return NULL;
			}

			//  if one child-right pe then 
			else if (curr->left == NULL)
			{
				node* temp = curr->right;
				delete curr;
				return temp;
			}

			//if One child left pe 
			else if (curr->right == NULL)
			{
				node* temp = curr->left;
				delete curr;
				return temp;
			}

			//if two child nodes
			else
			{
				// Find smallest value in right subtree
				node* temp = curr->right;

				while (temp->left != NULL)
				{
					temp = temp->left;
				}


				curr->data = temp->data;

				// Delete duplicate node
				curr->right = deleteNode(curr->right, temp->data);
			}
		}

		cout<<"Root=" << root->data;
		return curr;
	}



};


int main() {

	BST obj;
	int val = 0;
	int n;
	cout << "Entre number of roots: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Entre number: ";
		cin >> val;
		obj.root = obj.insert(obj.root, val);
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
	int del;
	cout << "Enter value to delete: ";
	cin >> del;

	obj.root = obj.deleteNode(obj.root, del);

    
	cout << "After deletion:";
	obj.inorder(obj.root);



	return 0;
}