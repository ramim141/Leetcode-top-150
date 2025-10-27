int trap_dp(vector<int>& height) 
{
   int n = height.size();
    if(n <= 2) return 0; // No water can be trapped if there are less than 3 bars

    vector<int> left_max(n);
    vector<int> right_max(n);

    // Pass 1: Fill left_max array
    left_max[0] = height[0];
    for (int i = 1; i < n; ++i) {
        left_max[i] = max(left_max[i - 1], height[i]);
    }

    // Pass 2: Fill right_max array
    right_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        right_max[i] = max(right_max[i + 1], height[i]);
    }

    // Calculate total water trapped
    int total_water = 0;
    for (int i = 1; i < n - 1; ++i) {
        int water_at_i = min(left_max[i], right_max[i]) - height[i];
        if (water_at_i > 0) {
            total_water += water_at_i;
        }
    }
    return total_water;
}