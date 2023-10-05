class Solution
{
    int upto(string &str, int k){
        int left = 0, right = 0, distinct = 0, ans = 0;
        vector<int> map(26, 0);
        
        while(right < str.size()){
            int i = str[right] - 'a';
            map[i]++;
            
            if(map[i] == 1)
            distinct++;
            
            while(distinct > k){
                int i = str[left++] - 'a';
                map[i]--;
                
                if(map[i] == 0)
                distinct--;
            }
            
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
    
  public:
    long long int substrCount (string s, int k) {
        return upto(s, k) - upto(s, k-1);
    }
};