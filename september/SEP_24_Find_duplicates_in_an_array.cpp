class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        unordered_map<int, int> freq;
        vector<int> ans;
        
        for(int i = 0; i<n; i++){
            freq[arr[i]]++;
        }
        
        for(int i = 0; i<n; i++){
            if(freq[i] > 1)
            ans.push_back(i);
        }
        
        if(ans.empty())
        return {-1};
        return ans;
    }
};