// O(4 ^ N) Solution


#include <stdio.h>
#include <stdbool.h>

int sz = 0;

void f(int x, int n, int p[], int a[])
{
    // check x if is more than n
    if (x > n)
    {
        return;
    }

    // check x if it was already stored in array a
    bool found = false;
    for (int i = 0; i < sz; i++)
    {
        if (a[i] == x)
        {
            found = true;
            break;
        }
    }

    // if x wasn't stored yet, add it in array a
    if (found == false)
    {
        a[sz] = x;
        sz = sz + 1;
    }

    // find more possible numbers
    for (int i = 0; i < 4; i++)
    {
        f(x + p[i], n, p, a);
    }
    return;
}

int main(void)
{
    // input
    int p[4] = {8, 12, 15, 20};
    int n = 100;

    // if n is the maximum number of grilled pork, n + 1 is all possible numbers (include 0)
    int a[n + 1];

    // find all possible numbers
    f(0, n, p, a);

    // find maximum number that isn't in array a
    for (int i = n; i > 0; i--)
    {
        bool found = false;
        for (int j = 0; j < sz; j++)
        {
            if (a[j] == i)
            {
                found = true;
                break;
            }
        }
        if (found == false)
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}