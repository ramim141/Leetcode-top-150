# Problem: Remove Element
# Approach: Two Pointer (Optimized)
# Time Complexity: O(n)
# Space Complexity: O(1)

def removeElement_optimized(nums: list[int], val: int) -> int:
    i = 0
    n = len(nums)
    
    while i < n:
        if nums[i] == val:
            nums[i] = nums[n - 1]
            n -= 1
        else:
            i += 1
            
    return n