class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        return adj;
    }
};