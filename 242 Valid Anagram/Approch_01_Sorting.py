def isAnagram_sorting(s: str, t: str) -> bool:
    # Step 1: Check if lengths are different. If so, they can't be anagrams.
    if len(s) != len(t):
        return False
    
    # Step 2 & 3: Sort both strings and compare them.
    # sorted() function returns a sorted list of characters.
    # For example, sorted("anagram") -> ['a', 'a', 'a', 'g', 'm', 'n', 'r']
    return sorted(s) == sorted(t)


# Test cases
print(isAnagram_sorting("anagram", "nagaram"))  # True
print(isAnagram_sorting("rat", "car"))          # False