#include <iostream>

using namespace std;

/**
 * 数组a, 待查找值为x
 * f(i, j)
 *      = -1,                 i > j
 *      = (i + j) / 2,        x = a[(i+j)/2]
 *      = f((i+j)/2 + 1, j),  x > a[(i+j)/2]
 *      = f(i, (i+j)/2 - 1),  x < a[(i+j)/2]
 */

int binarySearch(int a[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (target == a[mid])
            return mid;
        else if (target > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int a[] = {1,3,5,7,9,11};
    cout << binarySearch(a, 0, sizeof(a)/sizeof(int), 9) << endl;
    return 0;
}
