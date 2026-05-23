//#include<iostream>
//using namespace std;
//
//class node {
//public:          
//	int data;
//	node* left;
//	node* right;
//
//};
//
//class BST {
//public:
//	node* root;
//
//	BST() {
//		root = NULL;
//	}
//
//	void create() {
//		int count = 0;      // we take this sooo user will put 7 values
//		
//		node* curr;
//
//		while (count < 7) {
//			if (root == NULL) {                   // root node ke lia---the first value entred would be root node
//				root = new node;
//				cout << "Entre value: ";
//				cin >> root->data;
//				root->left = NULL;
//				root->right = NULL;
//				count++;
//			}
//			else {
//				curr = root;                         
//				int value;                               
//				cout << "Entre value: ";
//				cin >> value;
//
//				while (true) {                              // wehn root node created then we will see if it is min or max compared to root node
//					if (value < curr->data) {                   // if less then check kee left tree me koi node ha(curr->left==NULL) ---if no node then create a new node there and put it to left
//						if (curr->left==NULL) {                      
//							curr->left = new node;
//							curr = curr->left;
//							curr->data = value;
//							curr->left = NULL;
//							curr->right = NULL;
//							break;
//
//						}
//						else {
//							curr = curr->left;         // agr left pe phla se node ha then move the curret-----this will work until it finds a left node that in NULL taka left pe wo value add kr saka
//
//						}
//
//					}
//					else if (value > curr->data) {              // same wohi right ke lia 
//						                                          // if biger than the root value then right pe aa jao
//
//						if (curr->right == NULL) {
//							curr->right = new node;
//							curr = curr->right;                     //check if right node id NULL if yes then add new node
//							curr->data = value;
//							curr->right = NULL;
//							curr->left = NULL;
//							break;
//						}
//						else {
//							curr = curr->right;                 // if no then move curr to next
//						}
//
//					}
//					else {
//						cout << "No duplicate" << endl;
//						break;
//					}
//
//
//				}
//				count++;        // update count taa ke 7 values add ho
//
//			}
//
//
//
//		}
//
//
//	}
//
//	void inorder(node* curr) {
//		if (curr != NULL) {
//			inorder(curr->left);         // inorder recurrsive me work kra gaaa -----phla left subtree sra print kra ga then right pe
//			cout << curr->data << endl;    
//			inorder(curr->right);
//		}
//	}
//
//	bool search(node* root, int key)
//	{
//		
//		if (root == NULL)
//		{
//			return false;
//		}
//
//		
//		if (root->data == key)         // Value found --if key==root then found already
//		{
//			return true;
//		}
//
//		
//		if (key < root->data)               // agr key is less than root go to left subtree and search
//		{
//			return search(root->left, key);
//		}
//
//		return search(root->right, key);
//		// Search in right subtree after
//	}  
//
//
//
//};
//
//int main() {
//
//	BST obj;
//	obj.create();
//	obj.inorder(obj.root);
//
//	int n;
//	cout << "Enter value to search: ";
//	cin >> n;
//
//	if (obj.search(obj.root, n))
//	{
//		cout << "Value found in BST." << endl;
//	}
//	else
//	{
//		cout << "Value does not exist in BST." << endl;
//	}
//
//
//	return 0;
//}