class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    queue<int> q;
	    vector<int> visited(V, false);
	    
	    q.push(0);
	    visited[0] = true;
	    int level = 0;
	    
	    while(!q.empty()){
	        int size = q.size();
	        
	        while(size--){
	            
	            int curr = q.front();
	            q.pop();
	            
	            if(curr == X) return level;
	            for(auto v : adj[curr]){
	                if(!visited[v]){
	                    visited[v] = true;
	                    q.push(v);
	                }
	            }
	            
	        }
	        level++;
	    }
	    return -1;
	    
	}
};