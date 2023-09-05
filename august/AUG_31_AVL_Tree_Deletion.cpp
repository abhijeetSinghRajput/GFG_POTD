/* Node is as follows:

struct Node
{
    int data, height;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

*/

int heightOf(Node *root)
{
    if (!root)
        return 0;
    else
        return root->height;
}

int getBalanceFactor(Node *root)
{
    if (!root)
        return 0;
    return heightOf(root->left) - heightOf(root->right);
}
void updateHeight(Node *node)
{
    node->height = max(heightOf(node->left), heightOf(node->right)) + 1;
}
Node *leftRotation(Node *root)
{
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;

    updateHeight(root);
    updateHeight(temp);

    return temp;
}

Node *rightRotation(Node *root)
{
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;

    updateHeight(root);
    updateHeight(temp);

    return temp;
}

int rightMin(Node *root)
{
    root = root->right;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
Node *deleteNode(Node *root, int data)
{
    // add code here,
    if (!root)
        return NULL;

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // leaf node
        Node *toDelete = root;
        if (!root->left && !root->right)
        {
            delete (root);
            return NULL;
        }
        // node having one child
        else if (root->left && !root->right)
        {
            Node *left = root->left;
            delete (toDelete);
            return left;
        }
        else if (!root->left && root->right)
        {
            Node *right = root->right;
            delete (toDelete);
            return right;
        }

        // node having one child
        // node having both children
        else
        {
            int newData = rightMin(root);
            root->data = newData;
            root->right = deleteNode(root->right, newData);
        }
    }

    updateHeight(root);
    int balanceFactor = getBalanceFactor(root);

    // left left
    if (balanceFactor > 1 && getBalanceFactor(root->left) >= 0)
    {
        return rightRotation(root);
    }
    // left right
    else if (balanceFactor > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    // right left
    else if (balanceFactor < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    // right right
    else if (balanceFactor < -1 && getBalanceFactor(root->right) <= 0)
    {
        return leftRotation(root);
    }

    return root;
}