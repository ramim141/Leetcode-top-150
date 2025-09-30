from collections import Counter

def isAnagram_pythonic(s: str, t: str) -> bool:
    # Counter creates a hash map of character counts automatically.
    # Counter("anagram") -> {'a': 3, 'n': 1, 'g': 1, 'r': 1, 'm': 1}
    # Two Counter objects are equal if their keys and counts are the same.
    return Counter(s) == Counter(t)
# Test cases
print(isAnagram_pythonic("anagram", "nagaram"))  # True
print(isAnagram_pythonic("rat", "car"))          # False