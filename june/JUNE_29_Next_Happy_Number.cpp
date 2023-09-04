class Solution{
public:
    //1234
    //1*1 + 2*2 + 3*3 + 4*4
    int sumOfSquare(int num){
        int sum = 0;
        while(num){
            int lastDigit = num % 10;
            sum += lastDigit*lastDigit;
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int N){
        while(true){
            N = sumOfSquare(N);
            if(N == 20){
                return false;
            }
            else if(N == 1){
                return true;
            }
        }
    }
    int nextHappy(int N){
        // code here
        N++;
        while(true)
        {
            if(isHappy(N))
            {
                return N;
            }
            else
            {
                N++;
            }
        }
    }
};