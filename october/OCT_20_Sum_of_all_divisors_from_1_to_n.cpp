class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        long long sum =  0;
        // value (N/i) repeats i times for each f(i)
        for(int i = 1; i<=N; i++){
            sum += (N/i) *i;
        }
        return sum;
    }
};