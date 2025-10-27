# Merge and Sort Approach
# Time Complexity: O((m + n) log(m + n))
# Space Complexity: O(1)
def merge_and_sort(nums1: list[int], m: int, nums2: list[int], n: int):
    for i in range(n):
        nums1[m + i] = nums2[i]
    nums1.sort()