#include <iostream>

using namespace std;

/**
 * b[j]表示以为a[j]结尾的子序列的和的最大值(最值在遍历过程中即可求得，故不需要使用数组b[])
 *
 * b[j] = max{b[j-1] + a[j], a[j]}
 * 即
 * b[j]
 *   = b[j-1] + a[j],  b[j-1] > 0,
 *   = a[j],           b[j-1] <= 0
 */
int MaxSum(int a[], int n)
{
    int maxSum = 0;
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        if (b > 0)
            b += a[i];
        else
            b = a[i];
        if (b > maxSum)
            maxSum = b;
    }
    return maxSum;
}

int main()
{
    int arr[] = {2,-1,3,-2,-3, 6};
    cout << MaxSum(arr, sizeof(arr)/sizeof(int)) << endl;
    return 0;
}
