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

    memcpy(a + left, tmp, k * sizeof(int));   // 第三个参数为拷贝的字节数
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
    int x[10] = {1,3,5,7,9,2,4,6,8,10};
    Merge(x, 0, 4, 9);
    for (int i=0; i<10; i++)
        cout << x[i] << " ";
    cout << endl;

    return 0;
}
