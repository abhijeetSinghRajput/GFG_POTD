class Solution{
public:
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        for(int gap = 0; gap < n; gap++){
            for(int i = 0, j = gap; j < n; i++, j++){
                if(gap == 0){
                    isPalindrome[i][j] = true;
                }
                else if(gap == 1 && str[i] == str[j]){
                    isPalindrome[i][j] = true;
                }
                else if(str[i] == str[j] && isPalindrome[i+1][j-1]){
                    isPalindrome[i][j] = true;
                }
            }
        }

        if(isPalindrome[0][n-1]) return 0;

        // vector<vector<int>> dp(n, vector<int>(n, 0));

        // for(int gap = 0; gap < n; gap++){
        //     for(int i = 0, j = gap; j < n; i++, j++){
        //         if(isPalindrome[i][j]){
        //             dp[i][j] = 0;
        //         }
        //         else if(gap == 1){
        //             dp[i][j] = 1;
        //         }
        //         else{
        //             int mn = INT_MAX;
        //             for(int k = i; k < j; k++){
        //                 mn = min(mn, dp[i][k] + dp[k+1][j]);
        //             }
        //             dp[i][j] = mn + 1;
        //         }
        //     }
        // }
        // return dp[0][n-1];
        
        int dp[n];
        dp[0] = 0;
        
        for(int i = 1; i<n; i++){
            if(isPalindrome[0][i]){
                dp[i] = 0;
            }
            else{
                int mn = INT_MAX;
                for(int j = i; j>=1; j--){
                    
                    //........ |........|
                    //         j plndn i
                    if(isPalindrome[j][i]){
                        mn = min(mn, dp[j-1]);
                    }
                }
                dp[i] = mn + 1;
            }
        }
        return dp[n-1];
    }
};