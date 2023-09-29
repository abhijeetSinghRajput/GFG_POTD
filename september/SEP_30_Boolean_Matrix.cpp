class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // 1 0 0 0
        // 1 0 0 0
        // 1 0 0 0
        // 1 0 1 0
        // 0 0 0 0
    
        vector<bool> row(matrix.size(), false), col(matrix[0].size(), false);
        
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 1){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 1;
                }
            }
        }
    }
};