# Approach 02: Using Extra Array
# Time Complexity: O(N)
# Space Complexity: O(N)
def rotate_extra_array(nums: list[int], k: int):
    n = len(nums)
    k %= n

    # নতুন অ্যারে তৈরি
    result = [0] * n

    for i in range(n):
        new_index = (i + k) % n
        result[new_index] = nums[i]

    # ফলাফল মূল অ্যারেতে কপি করা
    # nums[:] is crucial for in-place modification
    nums[:] = result
