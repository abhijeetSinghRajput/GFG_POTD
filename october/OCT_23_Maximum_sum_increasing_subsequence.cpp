
class Solution{
	int N;
	vector<int> dp;
    int solve(int i,int sum, int arr[]){
        if(i >= N) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        for(int j = i+1; j < N;j++){
            if(arr[i] < arr[j])
            ans = max(ans, arr[j] + solve(j, sum + arr[j], arr));
        }
        return dp[i]  = ans;
    }
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    this->N =n;
	    int ans = 0;
	    dp.resize(n, -1);
	    for(int i = 0; i<n; i++){
	        ans = max(ans, arr[i] + solve(i, arr[i], arr));
	    }
	    return ans;
	}  
};