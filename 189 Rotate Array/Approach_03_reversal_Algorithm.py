# Approach 03: Reversal Algorithm
# Time Complexity: O(N)
# Space Complexity: O(1)
def rotate(self, nums, k):
    n = len(nums)
    k = k % n

    if k == 0:
        return

    nums.reverse()
    nums[:k] = nums[:k][::-1]
    nums[k:] = nums[k:][::-1]
