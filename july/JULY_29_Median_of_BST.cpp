

/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
void traverse(struct Node *root, vector<int> &arr)
{
    if (root == NULL)
        return;
    traverse(root->left, arr);
    arr.push_back(root->data);
    traverse(root->right, arr);
}
float findMedian(struct Node *root)
{
    // Code here
    vector<int> arr;
    traverse(root, arr);
    int n = arr.size();
    float ans;
    if ((n & 1) == 0)
        ans = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    else
        ans = arr[n / 2];
    //   for(i : arr)
    //     printf("%d ",i);
    // cout<<endl;

    return ans;
}