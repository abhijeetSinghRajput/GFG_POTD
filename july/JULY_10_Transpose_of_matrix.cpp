class Solution
{
public:
    // Function to find transpose of a matrix.
    void transpose(vector<vector<int>> &matrix, int n)
    {
        // code here
        int a = 0;
        for (int i = a; i < n; i++)
        {
            for (int j = a; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
            a++;
        }
    }
};