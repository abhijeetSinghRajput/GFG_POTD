class Solution {
    //jo jo cycle ke part hai vo safe node nhi ho skta
    vector<bool> cyclicNode, visited, backtrack;
    
    bool isCyclic(int source, auto adj[]){
        visited[source] = true;
        backtrack[source] = true;
        
        for(auto u : adj[source]){
            if(visited[u] && backtrack[u]) return true;
            else if(!visited[u] && isCyclic(u, adj)) 
            return cyclicNode[u] = true;
        }
        
        backtrack[source] = false;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        visited.resize(V, false);
        backtrack.resize(V, false);
        cyclicNode.resize(V, false);
        
        for(int i = 0; i<V; i++){
            if(!visited[i]) 
            cyclicNode[i] = isCyclic(i, adj);
        }
        
        vector<int> ans;
        for(int i = 0; i<V; i++){
            if(!cyclicNode[i])
            ans.push_back(i);
        }
        return ans;
    }
};