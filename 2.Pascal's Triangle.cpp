#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n)
{
    vector<vector<long long int>> matrix(n);

    for (int i = 0; i < n; i++)
    {
        matrix[i].resize(i + 1);
        matrix[i][0] = 1;
        matrix[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
        }
    }
    return matrix;
}
