#include <iostream>

using namespace std;

#define N  3

/**
 * 矩阵连乘
 * m[i][j]
 *       = 0, i == j
 *       = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j], i <= k < j，（其中p[i]表示矩阵i的列数）
 */
void MatrixChain(int n, int *row, int *col, int m[][N], int s[][N])
{
    for (int i = 0; i < n; i++)
        m[i][i] = 0;
    for (int d = 1; d < n; d++)
    {
        for (int i = 0; i < n - d; i++)
        {
            int j = i + d;
            int tmp;
            for (int k = i; k < j; k++)
            {
                tmp = m[i][k] + m[k+1][j] + row[i]*col[k]*col[j];
                if (tmp < m[i][j] || i == k)
                {
                    m[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
    }
}


void Traceback(int i, int j, int s[][N])
{
    if (i < j)
    {
        if (i < s[i][j])
            cout << "(";
        Traceback(i, s[i][j], s);
        if (i < s[i][j])
            cout << ")";

        if (s[i][j] + 1 < j)
            cout << "(";
        Traceback(s[i][j]+1, j,s);
        if (s[i][j] + 1 < j)
            cout << ")";
    }
    else
    {
        cout << i;
    }
}


void clean(int m[][N], int s[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j= 0; j < N; j++)
        {
            m[i][j] = -1;
            s[i][j] = -1;
        }
    }
}


int main()
{
    int row[3] = {2, 3, 2};
    int col[3] = {3, 2, 1};
    int m[N][N], s[N][N];

    clean(m, s);

    MatrixChain(N, row, col, m, s);
    cout << "Min multiply times: " << m[0][N-1] << endl;
    cout << "Calculate method: ";
    Traceback(0, N-1, s);

    return 0;
}

