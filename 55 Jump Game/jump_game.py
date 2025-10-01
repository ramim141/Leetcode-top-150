# Time Complexity: O(n)
# Space Complexity: O(1)

def canJump(nums: list[int]) -> bool:
    # farthest_reach ট্র্যাক করবে আমরা সর্বোচ্চ কতদূর পৌঁছাতে পারি।
    farthest_reach = 0
    n = len(nums)
    
    for i, num in enumerate(nums):
        # যদি বর্তমান ইনডেক্স (i) আমাদের সর্বোচ্চ পৌঁছানোর সীমার বাইরে হয়,
        # তার মানে আমরা এখানে পৌঁছাতেই পারব না।
        if i > farthest_reach:
            return False
        
        # আমাদের সর্বোচ্চ পৌঁছানোর সীমাকে আপডেট করি।
        # বর্তমান অবস্থান (i) থেকে লাফ দিয়ে (num) আমরা i + num পর্যন্ত যেতে পারি।
        farthest_reach = max(farthest_reach, i + num)
        
        # একটি অপ্টিমাইজেশন: যদি আমাদের পৌঁছানোর সীমা শেষ ইনডেক্স বা তার বেশি হয়ে যায়,
        # তাহলে আর চেক করার দরকার নেই, আমরা নিশ্চিতভাবে পৌঁছাতে পারব।
        if farthest_reach >= n - 1:
            return True
            
    # যদি লুপ শেষ হয়, তার মানে আমরা শেষ পর্যন্ত পৌঁছেছি।
    return True

# Example Usage:
nums1 = [2, 3, 1, 1, 4]
print(f"For {nums1}, can we reach the end? {canJump(nums1)}") # Output: True

nums2 = [3, 2, 1, 0, 4]
print(f"For {nums2}, can we reach the end? {canJump(nums2)}") # Output: False
