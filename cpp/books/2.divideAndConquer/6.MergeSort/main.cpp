#include <iostream>
#include <string.h>

using namespace std;

/**
 * T(n)
 *    = O(1),            n = 1
 *    = 2T(n/2) + O(1),  n > 1
 */

void Merge(int a[], int left, int mid, int right)
{
    int* tmp = new int[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while (i <= mid)
        tmp[k++] = a[i++];

    while (j <= right)
        tmp[k++] = a[j++];

    memcpy(a + left, tmp, k * sizeof(int));   // 第三个参数为拷贝的字节数，同memset
    delete tmp;
}

// 对数组a的[left, right]元素排序
void MergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(a, left, mid);
        MergeSort(a, mid+1, right);
        Merge(a, left, mid, right);
    }
}

int main()
{
    int a[] = {34,65,12,43,67,5,78,10,3,70};
    int len = sizeof(a) / sizeof(int);
    MergeSort(a, 0, len - 1);
    for (int i=0; i< len; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
