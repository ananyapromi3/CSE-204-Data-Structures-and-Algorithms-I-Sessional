#include <iostream>
#include "BST.cpp"
#include <cstring>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BST *bst;
    bst = new BST();
    bst->displayBST();
    char c1, c2[5];

    while (cin >> c1 >> c2)
    {
        if (c1 == 'I')
        {
            bst->insert(atoi(c2));
            bst->displayBST();
        }
        else if (c1 == 'D')
        {
            if (bst->deleteNode(atoi(c2)))
            {
                bst->displayBST();
            }
        }
        else if (c1 == 'F')
        {
            if (bst->find(atoi(c2)))
            {
                cout << "True\n";
            }
            else
            {
                cout << "False\n";
            }
        }
        else if (c1 == 'T')
        {
            if (!strcmp(c2, "In"))
            {
                bst->inorderTraversal();
            }
            else if (!strcmp(c2, "Pre"))
            {
                bst->preorderTraversal();
            }
            else if (!strcmp(c2, "Post"))
            {
                bst->postorderTraversal();
            }
        }
        else
        {
            cout << "Invalid Input\n";
        }
    }

    // cout << "\n"
    //      << bst->depthBST() << "\n";
}

// I 10
// I 11
// F 6
// I 6
// F 6
// I 4
// F 11
// I 17
// I 8
// I 7
// I 21
// I 9
// T In
// T Pre
// T Post
// F 9
// D 9
// F 9
// D 11
// F 11