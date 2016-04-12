#include <iostream>

using namespace std;

/**
 * R = {r1, r2, ... , rn}, Ri = R - {ri}
 * Perm(X)
 *       = (r), n = 1
 *       = (r1)Perm(R1) + (r2)Perm(R2) + ... + (rn)Perm(Rn),  n > 1
 */
template <class Type>
void perm(Type arr[], int k, int m)
{
    // 生成arr[k:m)的所有排列
    if (k == m)
    {
        for (int i=0; i<m; i++)
            cout << arr[i];
        cout << endl;
    }
    else
    {
        for (int i=k; i<m; i++)
        {
            swap(arr[k], arr[i]);
            perm(arr, k+1, m);
            swap(arr[k], arr[i]);
        }
    }
}


int main()
{
    int l[] = {1,2,3,4};
    perm(l, 0, sizeof(l)/sizeof(int));
    return 0;
}
