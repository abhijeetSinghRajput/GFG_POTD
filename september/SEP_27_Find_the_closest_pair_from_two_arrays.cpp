class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code herej
        int left = 0 , right = m-1;
        int diff = INT_MAX;
        vector<int> pair(2);
        while(left < n && right >= 0){
            int sum = arr[left] + brr[right];
            
            if(abs(sum - x) < diff){
                diff = abs(sum - x);
                pair[0] = arr[left];
                pair[1] = brr[right];
            }
            
            if(sum < x){
               left++; 
            }
            else{
                right--;
            }
        }
        return pair;
    }
};