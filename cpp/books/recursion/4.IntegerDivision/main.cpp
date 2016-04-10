#include <iostream>

using namespace std;

/**
 * n,m > 0, q(n, m)表示n的所有不同划分中，最大加数不超过m的划分个数
 * q(n, m)
 *       = 0,                       n < 1 or m < 1
 *       = 1,                       n = m = 1
 *       = q(n, n),                 1 <= n < m
 *       = 1 + q(n, n-1),           n = m >= 1
 *       = q(n, m-1) + q(n-m, m),   n > m > 1
 */
int getDivisions(int n, int m)
{
    if (n < 1 || m < 1)
        return 0;
    if (n == 1 && m == 1)
        return 1;
    if (n < m)
        return getDivisions(n, n);
    if (n == m)
        return getDivisions(n, n - 1) + 1;
    return getDivisions(n, m - 1) + getDivisions(n - m, m);
}

int main()
{
    cout << getDivisions(6, 6) << endl;
    return 0;
}
