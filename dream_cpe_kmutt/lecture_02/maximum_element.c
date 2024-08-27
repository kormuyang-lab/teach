#include <stdio.h>

int main(void)
{
    // input
    int n; // size of array
    int max_element; // answer
    scanf("%d", &n);

    int a[n]; // array size n
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // process, algorithm
    max_element = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max_element)
        {
            max_element = a[i];
        }
    }

    // output
    printf("%d\n", max_element);
    return 0;
}