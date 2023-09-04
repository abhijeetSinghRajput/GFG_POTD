class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        vector<bool> traversed(V, false);
        queue<int> q;

        q.push(0);
        traversed[0] = true;

        while (!q.empty())
        {
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for (int i : adj[curr])
            {
                if (!traversed[i])
                {
                    q.push(i);
                    traversed[i] = true;
                }
            }
        }

        return ans;
    }
};