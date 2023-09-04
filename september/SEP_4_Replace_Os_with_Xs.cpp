class Solution{
    void dfs(int i, int j, vector<vector<char>> &mat){
        //handling out bound
        if(i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
        return;
        
        //base case
        if(mat[i][j] != 'O')
        return;
        
        //mark as visited (INVALID) as it coming from boundaries
        mat[i][j] = 'I';
        
        dfs(i-1, j, mat);//top
        dfs(i+1, j, mat);//bottom
        dfs(i, j-1, mat);//left
        dfs(i, j+1, mat);//right
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        //enter from boundary and start traversing 
        
        //traversing the boundaris
        //and entering from outer most opening
        for(int i = 0; i<n; i++){
            //left bound
            if(mat[i][0] == 'O'){
                dfs(i, 0, mat);
            }
            //right bound
            if(mat[i][m-1] == 'O'){
                dfs(i, m-1, mat);
            }
        }
        for(int i = 0; i<m; i++){
            //top bound
            if(mat[0][i] == 'O'){
                dfs(0, i, mat);
            }
            //bottom bound
            if(mat[n-1][i] == 'O'){
                dfs(n-1, i, mat);
            }
        }
        
        for(auto &vec : mat){
            for(auto &i : vec){
                if(i == 'I')
                    i = 'O';
                else if(i == 'O')
                    i = 'X';
            }
        }
        
        return mat;
    }
};