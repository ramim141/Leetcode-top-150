from collections import defaultdict

def isAnagram_hashMap(s: str, t: str) -> bool:
    # Step 1: Check lengths
    if len(s) != len(t):
        return False
    
    # Step 2: Build frequency map
    char_counts = defaultdict(int)
    
    # Count characters for string s (increment)
    for char in s:
        char_counts[char] += 1
    
    # Decrement counts for string t
    for char in t:
        char_counts[char] -= 1
        # Optimization: if a character count goes below zero, they can't be anagrams
        if char_counts[char] < 0:
            return False
            
    # Step 3: Check if all counts are zero.
    # This check is actually implicitly handled by the loop above.
    # If the loop finishes without returning false, it means every character from t
    # found a corresponding character in s, and since the lengths are equal,
    # all counts must be zero.
    return True

# Test cases
print(isAnagram_hashMap("anagram", "nagaram"))  # True
print(isAnagram_hashMap("rat", "car"))  # False