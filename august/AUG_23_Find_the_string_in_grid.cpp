class Solution
{
    int N, M;
    // instead of copying word and grid in isFound()
    // I'm getting the '&' reference of these complex data type

    bool isFound(int i, int j, string &word, vector<vector<char>> &grid)
    {
        int n = word.size(), k;

        // moving right
        for (k = 0; k < n && j + k < M; k++)
        {
            if (grid[i][j + k] == word[k])
                continue;
            else
                break;
        }
        if (k >= n)
            return true;

        // moving left
        for (k = 0; k < n && j - k >= 0; k++)
        {
            if (grid[i][j - k] == word[k])
                continue;
            else
                break;
        }
        if (k >= n)
            return true;
        // moving top
        for (k = 0; k < n && i - k >= 0; k++)
        {
            if (grid[i - k][j] == word[k])
                continue;
            else
                break;
        }
        if (k >= n)
            return true;

        // moving bottom
        for (k = 0; k < n && i + k < N; k++)
        {
            if (grid[i + k][j] == word[k])
                continue;
            else
                break;
        }
        if (k >= n)
            return true;
        // moving top left
        for (k = 0; k < n && i - k >= 0 && j - k >= 0; k++)
        {
            if (grid[i - k][j - k] == word[k])
                continue;
            else
                break;
        }
        if (k >= n)
            return true;

        // moving top right
        for (k = 0; k < n && i - k >= 0 && j + k < M; k++)
        {
            if (grid[i - k][j + k] == word[k])
                continue;
            else
                break;
        }
        if (k >= n)
            return true;
        // moving bottom left
        for (k = 0; k < n && i + k < N && j - k >= 0; k++)
        {
            if (grid[i + k][j - k] == word[k])
                continue;
            else
                break;
        }
        if (k >= n)
            return true;

        // moving bottom right
        for (k = 0; k < n && i + k < N && j + k < M; k++)
        {
            if (grid[i + k][j + k] == word[k])
                continue;
            else
                break;
        }
        if (k >= n)
            return true;

        return false;
    }

public:
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        // Code here
        vector<vector<int>> ans;

        this->N = grid.size();
        this->M = grid[0].size();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                // this step will call the isFound() only when is there any possibility
                if (grid[i][j] == word[0])
                {
                    if (isFound(i, j, word, grid))
                        ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};