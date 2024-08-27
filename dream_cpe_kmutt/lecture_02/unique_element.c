#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // input
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // process
    bool unique = true;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                unique = false;
            }
        }
    }

    // output
    if (unique == true)
    {
        printf("Unique\n");
    }
    else
    {
        printf("Not unique\n");
    }
    return 0;
}