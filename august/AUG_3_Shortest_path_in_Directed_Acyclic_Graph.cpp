// User function Template for C++
class Solution
{
    void dfs(int s, vector<bool> &visited, auto adj[], stack<int> &stack)
    {
        visited[s] = true;
        // ADJ LIST
        //[0] {1 2} {4 1}
        //[1] {2 3}
        //[2] {3 6}
        //[3]
        //[4] {5 4} {2 2}
        //[5] {3 1}

        // adj[s] retpresent a vector of pair
        // i represent each pair of the vector

        for (auto i : adj[s])
        {
            if (!visited[i.first])
                dfs(i.first, visited, adj, stack);
        }
        // backtraking
        stack.push(s);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here
        vector<pair<int, int>> adj[N];

        // making adjacency list
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        // topo sort
        vector<bool> visited(N, false);
        stack<int> stack;
        vector<int> topoSort;

        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
                dfs(i, visited, adj, stack);
        }

        while (!stack.empty())
        {
            topoSort.push_back(stack.top());
            stack.pop();
        }
        // 0 4 5 1 2 3
        int max_value = 1e9;
        vector<int> distance(N, max_value);
        distance[0] = 0; // 0 will be the source

        // topoSort ke har ek element ko uthana hai first uske adjasent se compare krna hai
        for (int i : topoSort)
        {
            for (auto j : adj[i])
            {
                int v = j.first;  // adjacent
                int w = j.second; // weight
                distance[v] = min(distance[v], distance[i] + w);
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (distance[i] == max_value)
                distance[i] = -1;
        }
        return distance;
    }
};