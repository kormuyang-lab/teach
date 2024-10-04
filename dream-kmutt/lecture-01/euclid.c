#include <stdio.h>

int main(void)
{
    int max_number = 10, min_number = 20;
    
    // n1 = max, n2 = min
    if (max_number < min_number)
    {
        int temp_number = max_number; // temp_number == 6
        max_number = min_number; // max_number == 12
        min_number = temp_number; // min_number == 6
    }

    // while loop
    int fraction = max_number % min_number; // fraction == 3
    while (fraction != 0)
    {
        max_number = min_number; // max_number == 12
        min_number = fraction; // min_number == 3
        fraction = max_number % min_number; // fraction == 0
    }

    // for loop
    for (int fraction = max_number % min_number; fraction != 0; fraction = max_number % min_number)
    {
        max_number = min_number;
        min_number = fraction;
    }

    printf("result: %d\n", min_number);
    return 0;
}
