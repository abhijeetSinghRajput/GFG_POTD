class solution{
public:
    	bool checkTriplet(int arr[], int n) {
	    // code here
	    
	    //APPROACH 1 not gonna accepted
	    sort(arr, arr+n);
	    for(int i = 0; i<n; i++)
	    arr[i] *= arr[i];
	    
	    for(int i = n-1; i >= 0; i--){
	        int targetSum = arr[i];
	        int left = 0, right = i-1;
	        
	        //now the question requice to 'FIND PAIR EQUL TO TARGET SUM'
	        while(left < right){
	            int sum = arr[left] + arr[right];
	            
	            if(sum == targetSum){
	                return true;
	            }
	            else if(sum > targetSum){
	                right--;
	            }
	            else{
	                left++;
	            }
	        }
	    }
	    return false;
	    
	    
	    // APPROACH 2
	   
	   unordered_set<int> set;
	   for(int i = 0; i<n; i++){
	       set.insert(arr[i] * arr[i]);
	   }
	   
	   for(int i = 0; i<n; i++){
	       for(int j = i+1; j<n; j++){
	           int sum = (arr[i] * arr[i]) + (arr[j] * arr[j]);
	           if(set.find(sum) != set.end())
	           return true;
	       }
	   }
	   return false;
	   
	}
};