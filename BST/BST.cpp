#include <iostream>
#include "Node.cpp"
using namespace std;

class BST
{
    Node *root;

    void display(Node *node)
    {
        if (node != NULL)
        {
            cout << node->getValue();
        }
        if (node->leftChild || node->rightChild)
        {
            cout << "(";
            if (node->leftChild)
            {
                display(node->leftChild);
            }
            cout << ")";
            cout << "(";
            if (node->rightChild)
            {
                display(node->rightChild);
            }
            cout << ")";
        }
    }

    void inorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        inorder(node->leftChild);
        cout << node->getValue() << " ";
        inorder(node->rightChild);
    }

    void preorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->getValue() << " ";
        preorder(node->leftChild);
        preorder(node->rightChild);
    }

    void postorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        postorder(node->leftChild);
        postorder(node->rightChild);
        cout << node->getValue() << " ";
    }

    int depth(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else if (node->leftChild == NULL && node->rightChild == NULL)
        {
            return 1;
        }
        else
        {
            return 1 + max(depth(node->rightChild), depth(node->leftChild));
        }
    }

    bool ifBalanced(Node *node)
    {
        if (node == NULL)
        {
            return true;
        }
        if (!node->rightChild && !node->leftChild)
        {
            return true;
        }
        if (!node->rightChild)
        {
            if (!node->leftChild->rightChild && !node->leftChild->leftChild)
            {
                return true;
            }
            return false;
        }
        if (!node->leftChild)
        {
            if (!node->rightChild->rightChild && !node->rightChild->leftChild)
            {
                return true;
            }
            return false;
        }
        if (abs(depth(node->rightChild) - depth(node->leftChild)) <= 1)
        {
            if (ifBalanced(node->rightChild) && ifBalanced(node->rightChild))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

    bool checkBalance()
    {
        return ifBalanced(this->root);
    }

    void displayBST()
    {
        if (this->root == NULL)
        {
            cout << "Tree empty\n";
            return;
        }
        display(this->root);
        cout << "\n";
    }

    void insert(int value)
    {
        if (this->root == NULL)
        {
            root = new Node(value, NULL, NULL);
            return;
        }
        Node *temp;
        temp = root;
        while (true)
        {
            if (value < temp->getValue())
            {
                if (temp->leftChild == NULL)
                {
                    temp->leftChild = new Node(value, NULL, NULL);
                    break;
                }
                temp = temp->leftChild;
            }
            else if (value > temp->getValue())
            {
                if (temp->rightChild == NULL)
                {
                    temp->rightChild = new Node(value, NULL, NULL);
                    break;
                }
                temp = temp->rightChild;
            }
            else
            {
                cout << value << " is already there\n";
                break;
            }
        }
    }

    bool find(int value)
    {
        if (this->root == NULL)
        {
            cout << "Tree Empty\n";
            return false;
        }
        Node *temp;
        temp = root;
        while (true)
        {
            if (value < temp->getValue())
            {
                if (temp->leftChild == NULL)
                {
                    return false;
                }
                temp = temp->leftChild;
            }
            else if (value > temp->getValue())
            {
                if (temp->rightChild == NULL)
                {
                    return false;
                }
                temp = temp->rightChild;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    int deleteNode(int value)
    {
        if (this->root == NULL)
        {
            cout << "Tree Empty\n";
            return 0;
        }
        Node *temp;
        temp = root;
        if (this->root->getValue() == value && !this->root->rightChild && !this->root->leftChild)
        {
            this->root = NULL;
            return 1;
        }
        while (true)
        {
            if (value < temp->getValue())
            {
                if (temp->leftChild == NULL)
                {
                    cout << "Not found\n";
                    return 0;
                }
                else if (value == temp->leftChild->getValue())
                {
                    if (!temp->leftChild->leftChild && !temp->leftChild->rightChild)
                    {
                        temp->leftChild = NULL;
                        delete temp->leftChild;
                        return 1;
                    }
                    else
                    {
                        cout << "Invalid Operation\n";
                        return 0;
                    }
                }
                temp = temp->leftChild;
            }
            else if (value > temp->getValue())
            {
                if (temp->rightChild == NULL)
                {
                    cout << "Not found\n";
                    return 0;
                }
                else if (value == temp->rightChild->getValue())
                {
                    if (!temp->rightChild->leftChild && !temp->rightChild->rightChild)
                    {
                        temp->rightChild = NULL;
                        delete temp->rightChild;
                        return 1;
                    }
                    else
                    {
                        cout << "Invalid Operation\n";
                        return 0;
                    }
                }
                temp = temp->rightChild;
            }
        }
    }

    void inorderTraversal()
    {
        if (this->root == NULL)
        {
            cout << "Tree empty\n";
            return;
        }
        inorder(this->root);
        cout << "\n";
    }

    void preorderTraversal()
    {
        if (this->root == NULL)
        {
            cout << "Tree empty\n";
            return;
        }
        preorder(this->root);
        cout << "\n";
    }

    void postorderTraversal()
    {
        if (this->root == NULL)
        {
            cout << "Tree empty\n";
            return;
        }
        postorder(this->root);
        cout << "\n";
    }
};
