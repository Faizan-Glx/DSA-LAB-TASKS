#include <iostream>
using namespace std;

class node
{
public:
    node* LTree, * RTree;
    int data;
};

class BST
{
public:
    node* root;

    BST()
    {
        root = NULL;
    }

    void create()
    {
        node* p;
        int value, c = 0;

        while (c < 7)
        {
            if (root == NULL)
            {
                root = new node;
                cout << "enter value of root node\n";
                cin >> root->data;
                root->RTree = NULL;
                root->LTree = NULL;
                c++;
            }
            else
            {
                p = root;
                cout << "enter value of node\n";
                cin >> value;

                while (true)
                {
                    if (value < p->data)
                    {
                        if (p->LTree == NULL)
                        {
                            p->LTree = new node;
                            p = p->LTree;
                            p->data = value;
                            p->LTree = NULL;
                            p->RTree = NULL;
                            cout << "value entered in left\n";
                            break;
                        }
                        else
                        {
                            p = p->LTree;
                        }
                    }
                    else if (value > p->data)
                    {
                        if (p->RTree == NULL)
                        {
                            p->RTree = new node;
                            p = p->RTree;
                            p->data = value;
                            p->LTree = NULL;
                            p->RTree = NULL;
                            cout << "value entered in right\n";
                            break;
                        }
                        else
                        {
                            p = p->RTree;
                        }
                    }
                    else
                    {
                        cout << "duplicate value not allowed\n";
                        break;
                    }
                }

                c++;
            }
        }
    }

    void inorder(node* p)
    {
        if (p != NULL)
        {
            inorder(p->LTree);
            cout << p->data << endl;
            inorder(p->RTree);
        }
    }

    
};

int main()
{
    BST obj;
    obj.create();

    cout << "\nPrinting traversal in inorder\n";
    obj.inorder(obj.root);

   
    return 0;
}