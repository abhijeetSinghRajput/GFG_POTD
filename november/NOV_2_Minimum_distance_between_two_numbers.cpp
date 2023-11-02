class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        // unordered_map<int, int> lastSeen;
        
        // int ans = INT_MAX;
        // for(int i = 0; i<n; i++){
        //     if(a[i] == x && lastSeen.count(y)){
        //         ans = min(ans, i - lastSeen[y]);
        //     }
        //     else if(a[i] == y && lastSeen.count(x)){
        //         ans = min(ans, i - lastSeen[x]);
        //     }
            
        //     lastSeen[a[i]] = i;
        // };
        // if(ans == INT_MAX)
        // return -1;
        // return ans;
        
        int lastSeen_x = -1, lastSeen_y = -1;
        int ans = INT_MAX;
        
        for(int i = 0; i<n; i++){
            if(a[i] == x){
                if(lastSeen_y != -1){
                    ans = min(ans, i - lastSeen_y);
                }
                lastSeen_x = i;
            }
            else if(a[i] == y){
                if(lastSeen_x != -1){
                    ans = min(ans, i - lastSeen_x);
                }
                lastSeen_y = i;
            }
        }
        if(ans == INT_MAX)
        return -1;
        return ans;
    }
};