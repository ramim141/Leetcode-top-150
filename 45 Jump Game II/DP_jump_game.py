def jump_dp(nums: list[int]) -> int:
    n = len(nums)
    if n <= 1:
        return 0
    
    dp = [float('inf')] * n
    dp[0] = 0
    
    for i in range(1, n):
        for j in range(i):
            # যদি j থেকে i-তে পৌঁছানো যায়
            if j + nums[j] >= i:
                dp[i] = min(dp[i], dp[j] + 1)
    return dp[n-1]