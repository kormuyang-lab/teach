#include <stdio.h>

int calculate_roughness(int heights[])
{
    int roughness = 0;
    int n = sizeof(heights) / sizeof(heights[0]);
    for (int i = 0; i < n; i++)
    {
        roughness += abs(heights[i] - heights[i + 1]);
    }
    return roughness;
}

int fill_land(int land_heights[], int l, int m, int r)
{
    int n = sizeof(land_heights) / sizeof(land_heights[0]);
    int min_roughness = __INT_MAX__;
    
    for (int start = 0; start < n; start++)
    {
        int filled_land[n];
        for (int i = 0; i < n; i++)
        {
            filled_land[i] = land_heights[i];
        }
        int current_height = l;
        int pos = start;

        while (pos < n && current_height < m)
        {
            filled_land[pos] = max(filled_land[pos], current_height);
            current_height += 1;
            pos += 1;
        }

        current_height = m;
        while (pos < n && current_height > r)
        {
            filled_land[pos] = max(filled_land[pos], current_height);
            current_height -= 1;
            pos += 1;
        }
        
        min_roughness = min(min_roughness, calculate_roughness(filled_land));
    }
    
    return min_roughness;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int heights[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &heights[i]);
    }
    int l, m, r;
    scanf("%d%d%d", &l, &m, &r);
    print(fill_land(heights, l, m, r));
    return 0;
}