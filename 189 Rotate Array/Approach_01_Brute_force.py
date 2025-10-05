# Approach 01: Brute Force
# Time Complexity: O(N * K)
# Space Complexity: O(1)
def rotate_brute_force(nums: list[int], k: int):
    n = len(nums)
    k %= n  # k-এর মান ঠিক করা
    
    for _ in range(k):
        previous = nums.pop() # শেষ উপাদানটি O(1) সময়ে বের করা
        nums.insert(0, previous) # শুরুতে যোগ করা O(N) সময় নেয়