int trap_brute_force(vector<int>& height) 
{
    int n = height.size();
    if(n <= 2) return 0; // No water can be trapped if there are less than 3 bars

    int total_water = 0;

    for(int i = 1; i < n - 1; i++)
    {
        int max_left = 0;
        for(int j = i; j >= 0; j--)
        {
            max_left = max(max_left, height[j]);
        }
        int max_right = 0;
        for(int j = i; j < n; j++)
        {
            max_right = max(max_right, height[j]);
        }
        int water_at_i = min(max_left, max_right) - height[i];
        if (water_at_i > 0) {
            total_water += water_at_i;
        }
    }
    return total_water;
}