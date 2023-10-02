class Solution{
    int mod = 1e9+7;
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n = s.size(), dp[n+1];
	    
	    unordered_map<char, int> lastSeen;
	    dp[0] = 1;
	    for(int i = 1; i<=n; i++){
	        char ch = s[i-1];
	        
	        dp[i] = (dp[i-1] * 2) % mod;
	        
	        if(lastSeen.find(ch) != lastSeen.end()){
	           int lastIndex = lastSeen[ch];
	           // + mod is used to avoid -ve resultant (+mod) % mod = cancelled
	           dp[i] = (dp[i] - dp[lastIndex-1] + mod) % mod;
	        }
	        
	        //last seen of ch at index i
	        lastSeen[ch] = i;
	    }
	    return dp[n];
	}
};