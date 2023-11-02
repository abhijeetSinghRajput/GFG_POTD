class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // code here
        unordered_map<int, int> map;
        for(auto i : arr)
        map[i]++;
        
        for(int i = 0; i<N; i++)
        arr[i] = map[i+1];
    }
};