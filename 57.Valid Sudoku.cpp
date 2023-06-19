bool isValid(int row, int col, int k, int mat[9][9])
{
    for (int x = 0; x < 9; x++)
    {
        if (mat[row][x] == k)
            return false;

        if (mat[x][col] == k)
            return false;

        if (mat[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == k)
            return false;
    }
    return true;
}
bool sudukoSolver(int mat[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (mat[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isValid(i, j, k, mat))
                    {
                        mat[i][j] = k;

                        if (sudukoSolver(mat))
                            return true;
                        else
                            mat[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool isItSudoku(int matrix[9][9])
{
    return sudukoSolver(matrix);
}
