class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                bfs(adj, i, visited, ans);
        }
        return ans;
    }
    void bfs(vector<int> adj[], int source, vector<bool> &visited, vector<int> &ans)
    {
        visited[source] = true;
        ans.push_back(source);

        // now visited all adjacent of source
        for (int i : adj[source])
        {
            if (!visited[i])
                bfs(adj, i, visited, ans);
        }
    }
};