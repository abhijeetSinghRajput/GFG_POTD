class Solution
{
public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX], int n, int m, int k)
    {
        // Your code goes here.
        int count = 0;
        for (int i = 0; i <= n / 2; i++)
        {
            //---->>
            for (int J = i; J < m - i; J++)
            {
                count++;
                if (count == k)
                    return a[i][J];
                //   cout<<i<<J<<" ";
            }
            //   cout<<endl;

            //
            for (int K = i + 1; K < n - (i + 1); K++)
            {
                count++;
                if (count == k)
                    return a[K][m - (1 + i)];
                //   cout<<K<<m-(1+i)<<" ";
            }
            //   cout<<endl;

            //<<----
            for (int L = m - (1 + i); L >= i; L--)
            {
                count++;
                if (count == k)
                    return a[n - (1 + i)][L];
                // cout<<n-(1+i)<<L<<" ";
            }
            //   cout<<endl;

            // ^
            for (int M = n - (2 + i); M > i; M--)
            {
                count++;
                if (count == k)
                    return a[M][i];
                //   cout<<M<<i<<" ";
            }
            //   cout<<endl;
        } // outer for loop terminated
        return 0;
    }
};