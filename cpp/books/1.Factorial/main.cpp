#include <iostream>

using namespace std;


/**
 * f(n)
 *    = 1          , n = 0
 *    = f(n-1) * n , n > 0
 */


int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return factorial(n-1) * n;
}


int main()
{
    cout << factorial(3) << endl;
    return 0;
}
