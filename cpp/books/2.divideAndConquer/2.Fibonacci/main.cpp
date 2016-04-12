#include <iostream>

using namespace std;

#define MEMORY_SIZE 1000

/**
 * f(n)
 *    = 1,                 n = 0, 1
 *    = f(n-2) + f(n-1), n > 1
 */

int memory[MEMORY_SIZE] = {0};

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
    {
        // f(n-2)
        int far;
        if (memory[n-2] > 0)
            far = memory[n-2];
        else
        {
            far = fibonacci(n-2);
            memory[n-2] = far;
        }

        // f(n-1)
        int near;
        if (memory[n-1] > 0)
            near = memory[n-1];
        else
        {
            near = fibonacci(n-1);
            memory[n-1] = near;
        }

        // f(n-2) + f(n-1)
        return far + near;
    }
}


int main()
{
    cout << fibonacci(5) << endl;
    return 0;
}
