class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        
        for(int i = 0; i < n - 3; i++) {
            //we can't check next to prevent duplicate
            if(i > 0 && arr[i] == arr[i-1])
                continue;//preventing duplication
            
            for(int j = i+1; j < n - 2; j++) {
                if(j > i+1 && arr[j] == arr[j-1])
                    continue;//preventing duplication
                
                int left = j+1;
                int right = n-1;
                int targetSum = k - (arr[i] + arr[j]);
                
                while(left < right){
                    int sum = arr[left] + arr[right];
                    if(sum == targetSum){
                        ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                        
                        //preventing duplication
                        while(left < right && arr[left] == arr[left+1])
                            left++;
                        while(left < right && arr[right] == arr[right-1])
                            right--;
                        
                        left++;
                        right--;
                    }
                    else if(sum < targetSum){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        
        return ans;
    }
};