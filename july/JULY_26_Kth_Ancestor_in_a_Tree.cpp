
// User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function

void traverse(Node *root, int &currLevel, int k, int node, int &nodeAt, int &ans)
{
    if (root == NULL)
    {
        --currLevel;
        return;
    }
    if (root->data == node)
    {
        nodeAt = currLevel;
        --currLevel;
        return;
    }
    int currNode = root->data;
    traverse(root->left, ++currLevel, k, node, nodeAt, ans);
    if (currLevel == (nodeAt - k) and ans == -1)
        ans = currNode;

    traverse(root->right, ++currLevel, k, node, nodeAt, ans);
    if (currLevel == (nodeAt - k) and ans == -1)
        ans = currNode;

    --currLevel;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here

    // step1 node ko find kro
    // let, this is the path of recursive call
    //        root
    //         \ 
    //         \
    //         /
    //          \ 
    //          \
    //          key

    // ab lautenge bhi isi path se
    // lautate samay ki ky ap kth ancesstor ho yani is currleve == (keyAt - k)

    int currLevel = 1, valueAt = -1, nodeAt = -1, ans = -1;
    traverse(root, currLevel, k, node, nodeAt, ans);
    // printf("nodeAt %d\nancesstor %d\n",nodeAt, nodeAt-k);
    return ans;
}