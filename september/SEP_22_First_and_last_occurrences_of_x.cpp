class Solution
{
    //lower bound is the first occurance of number (x == arr[i]) 
    //or if a number is greater (x > arr[i]) {if x not present, it could be the ans}
    //both could be possibe to be ans, so condition will be    💡(arr[i] >= x)
    int lowerBound(int arr[], int n, int x){
        int ans = n;
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            
            if(arr[mid] >= x){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    
    
    
    //lower bound is the number greater than x
    //so the only condition will be  💡(arr[i] )
    
    int upperBound(int arr[], int n, int x){
        int ans = n;
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            
            if(arr[mid] > x){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    
    
    //only difference in those function is the sign (>=), (>)
public:
    vector<int> find(int arr[], int n , int x )
    {
        //💡 it's about finding the lowerBound(x) and upperBound(x), isn't it 
        int l = lowerBound(arr, n, x);
        int u = upperBound(arr, n, x);
        
        if(arr[l] != x)// !found
            return {-1, -1};
        
        
        return {l, u-1};
    }
};