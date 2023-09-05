class Solution
{
    bool isFix(int row, int col, int val, int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            if (grid[i][col] == val)
                return false;
            if (grid[row][i] == val)
                return false;
        }
        // there are three subrow and three subcol

        //(0 1 2) / 3 GIVES 0 th subgrid
        //(3 4 5) / 3 GIVES 1 th subgrid
        //(6 7 9) / 3 GIVES 2 th subgrid

        // ith subgrid * 3 gives starting index of subgrid

        int subrow, subcol;
        subrow = (row / 3) * 3;
        subcol = (col / 3) * 3;
        for (int i = subrow; i < subrow + 3; i++)
        {
            for (int j = subcol; j < subcol + 3; j++)
            {
                if (grid[i][j] == val)
                    return false;
            }
        }

        return true;
    }

public:
    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        // Your code here
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {

                // empty cell
                if (grid[i][j] == 0)
                {
                    for (int val = 1; val <= 9; val++)
                    {

                        if (isFix(i, j, val, grid))
                        {
                            grid[i][j] = val;
                            // agr solve kr ke de deta hai to return kr do true...
                            if (SolveSudoku(grid))
                                return true;
                            else
                            {
                                // backtrace
                                //..nhi to jaisa tha vaisa hi chhor do
                                grid[i][j] = 0;
                            }
                        }
                    }
                    // sara val try krne ke bad bhi true return nhi hua mtlb
                    return false;
                }
            }
        }
        // kahi koi cell empty ho hi na
        return true;
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        // Your code here
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
        }
    }
};