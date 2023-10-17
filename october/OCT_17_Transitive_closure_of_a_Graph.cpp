class Solution{
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        for(int k = 0; k<N; k++){
            for(int i= 0; i<N; i++){
                for(int j = 0; j<N; j++){
                    if( i == j || graph[i][k] && graph[k][j]){
                        //i se j tabhi jaya ja skta hai jab,
                        //ap k ke through j pe pahuch jaye
                        //    k
                        //  /   \
                        // i --> j
                        
                        graph[i][j] = 1;
                    }
                }
            }
        }
        return graph;
    }
};