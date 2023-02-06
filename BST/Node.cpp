class Node
{
    int value;

public:
    Node *leftChild;
    Node *rightChild;

    Node(int value, Node *leftChild, Node *rightChild)
    {
        this->value = value;
        this->leftChild = leftChild;
        this->rightChild = rightChild;
    }

    // Node(const Node &node)
    // {
    //     this->value = node.value;
    //     this->leftChild = node.leftChild;
    //     this->rightChild = node.rightChild;
    // }

    ~Node()
    {
        // delete leftChild;
        // delete rightChild;
    }

    int getValue() { return this->value; }
    void setValue(int value) { this->value = value; }
};