class Solution
{
    
  public:
    int minOperation(int n)
    {
        //code here.
        int operation;
        while(n){
            if(n%2 == 0) n/=2;
            else n -= 1;
            operation++;
        }
        return operation;
    }
};