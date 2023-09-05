
class Solution
{
public:
    int Count(vector<vector<int>> &matrix)
    {
        // Code here
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int zero = 0;
                if (matrix[i][j] == 1)
                {
                    // left
                    if (j - 1 >= 0 && matrix[i][j - 1] == 0)
                    {
                        zero++;
                    }
                    // right
                    if (j + 1 < m && matrix[i][j + 1] == 0)
                    {
                        zero++;
                    }
                    // top
                    if (i - 1 >= 0 && matrix[i - 1][j] == 0)
                    {
                        zero++;
                    }
                    // bottom
                    if (i + 1 < n && matrix[i + 1][j] == 0)
                    {
                        zero++;
                    }
                    // top-left
                    if (i - 1 >= 0 && j - 1 >= 0 && matrix[i - 1][j - 1] == 0)
                    {
                        zero++;
                    }
                    // top-right
                    if (i - 1 >= 0 && j + 1 < m && matrix[i - 1][j + 1] == 0)
                    {
                        zero++;
                    }
                    // bottom-left
                    if (i + 1 < n && j - 1 >= 0 && matrix[i + 1][j - 1] == 0)
                    {
                        zero++;
                    }
                    // bottom-right
                    if (i + 1 < n && j + 1 < m && matrix[i + 1][j + 1] == 0)
                    {
                        zero++;
                    }
                    if (zero != 0 && zero % 2 == 0)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};