#include <iostream>

using namespace std;

#define M 12
#define N 6

/**
 * c[i][j]记录序列Xi和Yj的最长公共子序列的长度
 *
 * c[i][j]
 *       = 0,                           i =  0 或 j = 0
 *       = c[i-1][j-1] + 1,             i,j > 0, x[i] = y[j]
 *       = max{c[i][j-1], c[i-1][j]},   i,j > 0, x[i] != y[j]
 */
void LCSLength(int m, int n, char x[], char y[], int c[][N], int b[][N])
{
    int i, j;
    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (i = 1; i <= n; i++)
        c[0][i] = 0;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j<= n; j++)
        {
            if (x[i] == y[j])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            }
            else if (c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
    }
}

void LCS(int i, int j, char x[], char y[], int b[][N])
{
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == 1)
    {
        LCS(i-1, j-1, x, y, b);
        cout << x[i] << " ";
    }
    else if (b[i][j] == 2)
        LCS(i-1, j, x, y, b);
    else
        LCS(i, j-1, x, y, b);
}


int main()
{
    char x[M] = {'\0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
    char y[N] = {'\0', 'A', 'D', 'Z', 'H', 'I'};
    int c[M][N];
    int b[M][N];
    LCSLength(M-1, N-1, x, y, c, b);
    LCS(M-1, N-1, x, y, b);
    cout << endl;
    return 0;
}
