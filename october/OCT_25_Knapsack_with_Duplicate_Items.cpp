class Solution{
    int n;
    vector<vector<int>> dp;
    int solve(int i, int capacity, int val[], int wt[]){
        //not fit in bag || outbound
        if(capacity <= 0 || i >= n){
            return 0;
        }
        
        //memoization
        if(dp[i][capacity] != -1) return dp[i][capacity];
        
        //take 
        int take = 0;
        if(capacity >= wt[i])
        take = val[i] + solve(i, capacity - wt[i], val, wt);
        //note take
        int notTake = solve(i+1, capacity, val, wt);
        
        return dp[i][capacity] = max(take, notTake);
    }
    
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        this->n = N;
        dp.resize(N+1, vector<int>(W+1, -1));
        return solve(0, W, val, wt);
    }
};