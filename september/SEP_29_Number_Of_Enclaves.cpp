class Solution {
    void dfs(int i, int j, vector<vector<int>> &grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        return;
        
        //marked as visited
        grid[i][j] = 0;
        
        dfs(i-1, j, grid);//up
        dfs(i+1, j, grid);//down
        dfs(i, j-1, grid);//left
        dfs(i, j+1, grid);//right
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        
        //traversing horizontal boundary
        for(int i = 0; i<m; i++){
            if(grid[0][i] == 1){
                dfs(0, i, grid);
            }
            if(grid[n-1][i] == 1){
                dfs(n-1, i, grid);
            }
        }
        
        //traversing vertical boundary
        for(int i = 0; i<n; i++){
            if(grid[i][0] == 1){
                dfs(i, 0, grid);   
            }
            if(grid[i][m-1] == 1){
                dfs(i, m-1, grid);
            }
        }
        
        
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1)
                count++;
            }
        }
        
        return count;
    }
};