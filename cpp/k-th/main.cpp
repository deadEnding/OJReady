#include <iostream>

using namespace std;

/**
 * 返回两个有序数组中第k大的元素
 */
int searchKth(int a[], int m, int b[], int n, int k) {

    if (m > n) {
        return searchKth(b, n, a, m, k);
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
        return searchKth(a + pa, m - pa, b, n, k - pa);
    } else if (a[pa - 1] > b[pb - 1]) {
        return searchKth(a, m, b + pb, n - pb, k - pb);
    } else {
        return a[pa - 1];
    }
}


int main()
{
    int a[5] = {1,3,5,7,9};
    int b[7] = {1,2,3,4,5,6,7};
    cout << searchKth(a, 5, b, 7, 7) << endl;
    return 0;
}
