// User function Template for C++

class Solution {
    int N, M;
    bool isValid(int i, int j){
        if(i<0 || j < 0 || i >= N || j >= M)
            return false;
        return true;
    }
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        //base case
        this->N = N;
        this->M = M;
        if(A[0][0] == 0)
        return -1;
        
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;
        int steps = 0;
        
        while(!q.empty()){
            //now q containg the vertices of first level
            //while !traversed all the vertices of first level
            int size = q.size();
            while(size--){
                int i, j;
                i = q.front().first;
                j = q.front().second;
                q.pop();
                
                //now visite all the adjacent of current
                if(i == X && j == Y)
                    return steps;
                    
                //left
                if(isValid(i, j-1) && !visited[i][j-1] && A[i][j-1] == 1){
                    visited[i][j-1] = true;
                    q.push({i, j-1});
                }
                //right
                if(isValid(i, j+1) && !visited[i][j+1] && A[i][j+1] == 1){
                    visited[i][j+1] = true;
                    q.push({i, j+1});
                }
                //up
                if(isValid(i-1, j) && !visited[i-1][j] && A[i-1][j] == 1){
                    visited[i-1][j] = true;
                    q.push({i-1, j});
                }
                //down
                if(isValid(i+1, j) && !visited[i+1][j] && A[i+1][j] == 1){
                    visited[i+1][j] = true;
                    q.push({i+1, j});
                }
            }
            steps++;
        }
        return -1;
    }
};