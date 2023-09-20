class Solution
{
  public:
    vector<int> rotate(int n, int d) {
        d %= 16;
        // Right rotation
        int rightBits = n & ((1 << d) - 1);
        int remains = n >> d;
        int x = (rightBits << (16 - d)) | remains;



        // Left rotation
        // D    exclude
        //___ _____________  
        //101 1100100000100   =  0000000000000101
        int leftBits = n >> (16 - d);
        remains = n & ((1 << (16 - d)) - 1);
        int y = (remains << d) | leftBits;

        return {y, x};
    }
};