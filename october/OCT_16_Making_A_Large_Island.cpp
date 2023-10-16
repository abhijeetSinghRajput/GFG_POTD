class Solution
{
    int n;
    int dfs(int i, int j, vector<vector<int>> &grid, int &index){
        //handling outBound cases 
        if(i < 0 || j < 0 || i >= n || j >= n) return 0;
        
        //Base case
        if(grid[i][j] != 1) return 0;
        
        //marked as visited and giving a flag to every island
        grid[i][j] = index;
        
        int area = 1;
        area += dfs(i-1, j, grid, index); //move up
        area += dfs(i+1, j, grid, index); //move down
        area += dfs(i, j-1, grid, index); //move left
        area += dfs(i, j+1, grid, index); //move right
        
        return area;
    }
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        
        
        this->n = grid.size();
        int index = 2, maxArea = 0; //uisng 2 to differentiate b/w 0 and 1
        unordered_map<int, int> map; //{index, area}
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                
                if(grid[i][j] == 1){
                    int area = dfs(i, j, grid, index);
                    map[index++] = area;
                    maxArea = max(maxArea, area);
                }
                
            }
        }
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                
                if(grid[i][j] == 0){
                    unordered_set<int> set;
                    
                    //outBoundCond.
                    if(i >= 1)      set.insert(grid[i-1][j]);
                    if(i < n-1)     set.insert(grid[i+1][j]);
                    if(j >= 1)      set.insert(grid[i][j-1]);
                    if(j < n-1)     set.insert(grid[i][j+1]);
                    
                    int area = 1;
                    for(auto neighbourIsland : set){
                        //incluidng area of neighbours after treaty
                        area += map[neighbourIsland];
                    }
                    
                    maxArea = max(maxArea, area);
                }
                
            }
        }
        
        return maxArea;
    }
};