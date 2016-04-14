#include <iostream>

using namespace std;

/**
 * T(n)
 *    = O(1),            n <= 1
 *    = 2T(n/2) + O(n),  n >  1
 */
int Partition(int a[], int left, int right)
{
   int i = left;
   int j = right;
   int x = a[left];
   while (i < j)
   {
        while (i < j && a[j] >= x)   j--;   // 从右向左找第一个小于x的数
        if (i < j)
            a[i++] = a[j];
        while (i < j && a[i] < x)  i++;    // 从左向右找第一个大于等于x的数
        if (i < j)
            a[j--] = a[i];
   }
   a[i] = x;   // i == j
   return i;
}

void QuickSort(int a[], int left, int right)
{
    if (left < right)
    {
        int p = Partition(a, left, right);
        QuickSort(a, left, p - 1);
        QuickSort(a, p + 1, right);
    }
}

int main()
{
    int a[] = {34,65,12,43,67,5,78,10,3,70};
    int len = sizeof(a) / sizeof(int);
    QuickSort(a, 0, len - 1);
    for (int i=0; i< len; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
