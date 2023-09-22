class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) {
    
        // Your code here
        long long sum = 0;
        for(int i = 0; i<n; i++){
            sum += arr[i];
        }
        long long prevSum = 0;
        for(int i = 0; i<n; i++){
            sum -= arr[i];
            if(prevSum == sum)
                return i+1;
            prevSum += arr[i];
        }
        return -1;
    }

};