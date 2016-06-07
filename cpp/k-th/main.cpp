#include <iostream>
#include <assert.h>

using namespace std;

/**
 * 快排的一次划分
 *
 * @param a: 数组a
 * @param i: 数组a的起始下标
 * @param j: 数组a的结束下标
 *
 * @return 划分后基准值的下标
 */
int Partition(int a[], int i, int j) {
    int x = a[i];
    while (i < j) {
        while (i < j && a[j] >= x) j--;
        if (i < j)
            a[i++] = a[j];
        while  (i < j && a[i] < x) i++;
        if (i < j)
            a[j--] = a[i];
    }
    a[i] = x;
    return i;
}

/**
 * 返回无序数组中第k小的元素
 *
 * @param a: 数组a
 * @param i: 数组a的起始下标
 * @param j: 数组a的结束下标
 * @param k: a[i...j]的第k小的元素
 *
 * @return 第k小的元素
 */
int SearchKth(int a[], int i, int j, int k) {
    int m = Partition(a, i, j);

    if (m - i < k - 1) {
        SearchKth(a, m + 1, j, k - (m - i + 1));
    } else if (m - i == k - 1) {
        return a[m];
    } else {
        SearchKth(a, i, m - 1, k);
    }
}


/**
 * 返回两个有序数组中第k小的元素
 *
 * @param a: 数组a
 * @param m: 数组a的长度
 * @param b: 数组b
 * @param n: 数组b的长度
 * @param k: 第k小的元素
 *
 * @return 第k小的元素
 */
int SearchKth(int a[], int m, int b[], int n, int k) {

    if (m > n) {
        return SearchKth(b, n, a, m, k);
    }
    if (m == 0) {
        return b[k-1];
    }
    if (k == 1) {
        return min(a[0], b[0]);
    }

    int pa = min(k/2, m);
    int pb = k - pa;
    if (a[pa - 1] < b[pb - 1]) {
        return SearchKth(a + pa, m - pa, b, n, k - pa);
    } else if (a[pa - 1] > b[pb - 1]) {
        return SearchKth(a, m, b + pb, n - pb, k - pb);
    } else {
        return a[pa - 1];
    }
}


int main()
{
    int a[10] = {4,2,5,6,1,0,9,8,3,7};

    for (int i = 1; i <= 10; i++)
        assert(SearchKth(a, 0, 9, i) == i-1);


    int b[4] = {3,5,6,9};
    int c[8] = {0,1,2,4,7,8,10,11};

    for (int i = 1; i <= 12; i++) {
        assert(SearchKth(b, 4, c, 8, i) == i-1);
    }

    cout << "Success" << endl;

    return 0;
}
