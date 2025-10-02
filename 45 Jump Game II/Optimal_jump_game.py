def jump_greedy(nums: list[int]) -> int:
    if len(nums) <= 1: return 0
    jumps = 0
    current_reach = 0
    farthest_reach = 0
    for i in range(len(nums) - 1):
        farthest_reach = max(farthest_reach, i + nums[i])
        if i == current_reach:
            jumps += 1
            current_reach = farthest_reach
    return jumps

