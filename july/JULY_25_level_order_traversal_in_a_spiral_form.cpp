

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
void traverse(Node *root, vector<pair<int, int>> &levelAndData, int &level, int &heightOfTree)
{
    if (root == NULL)
    {
        --level;
        return;
    }
    heightOfTree = max(heightOfTree, level);
    levelAndData.push_back({level, root->data});
    traverse(root->left, levelAndData, ++level, heightOfTree);
    traverse(root->right, levelAndData, ++level, heightOfTree);
    --level;
}
bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.first < y.first;
}
vector<int> findSpiral(Node *root)
{
    // Your code here
    int heightOfTree = -1;
    vector<pair<int, int>> levelAndData;
    vector<int> ans;
    int level = 0;

    traverse(root, levelAndData, level, heightOfTree);

    stack<int> stack;
    for (int i = 0; i <= heightOfTree; i++)
    {
        for (auto j : levelAndData)
        {

            if (i == j.first)
            {
                if (i % 2 == 0)
                {
                    stack.push(j.second);
                }
                else
                {
                    while (!stack.empty())
                    {
                        ans.push_back(stack.top());
                        stack.pop();
                    }
                    ans.push_back(j.second);
                }
            }
        }
    }
    while (!stack.empty())
    {
        ans.push_back(stack.top());
        stack.pop();
    }
    return ans;
}