class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    for(int i = 0, j = 0; i<n; i++){
	        if(arr[i] != 0){
	            swap(arr[i],arr[j++]);
	        }
	    }
	}
};