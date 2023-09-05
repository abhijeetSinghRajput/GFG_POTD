
class Solution
{
public:
    // Function to find minimum number of operations that are required
    // to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int>> matrix, int n)
    {
        // code here
        // r1 6  c1 8
        // r2 9  c2 6
        // r3 6  c3 7

        vector<int> row, col;
        int maxsum = INT_MIN;

        for (int i = 0; i < matrix.size(); i++)
        {

            int rowsum = 0, colsum = 0;
            for (int j = 0; j < matrix[0].size(); j++)
            {
                rowsum += matrix[i][j];
                colsum += matrix[j][i];
            }

            maxsum = max(maxsum, max(rowsum, colsum));
            row.push_back(rowsum);
            col.push_back(colsum);
        }

        int ans = 0;
        for (int i = 0; i < row.size(); i++)
        {
            row[i] = abs(maxsum - row[i]);
            col[i] = abs(maxsum - col[i]);
            ans += col[i];
        }

        return ans;
    }
};