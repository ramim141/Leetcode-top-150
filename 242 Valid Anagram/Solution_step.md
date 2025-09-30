
### **Problem Statement**

আপনাকে দুটি স্ট্রিং `s` এবং `t` দেওয়া হবে। আপনাকে বলতে হবে `t` স্ট্রিংটি `s` স্ট্রিংটির একটি anagram কি না।

**Anagram কী?** একটি অ্যানাগ্রাম হলো এমন একটি শব্দ বা বাক্যাংশ যা অন্য একটি শব্দ বা বাক্যাংশের অক্ষরগুলো পুনর্বিন্যাস (rearranging) করে তৈরি হয়। অর্থাৎ, দুটি স্ট্রিং-এ একই অক্ষর একই সংখ্যায় থাকতে হবে।

**উদাহরণ:**
*   `s = "anagram"`, `t = "nagaram"` -> `true` (দুটি স্ট্রিং-এই 'a' ৩টা, 'n' ১টা, 'g' ১টা, 'r' ১টা, 'm' ১টা আছে)।
*   `s = "rat"`, `t = "car"` -> `false` (অক্ষরগুলো এক নয়)।

---

### **The Core Idea**

দুটি স্ট্রিং অ্যানাগ্রাম হবে যদি এবং কেবল যদি তাদের মধ্যে থাকা প্রতিটি অক্ষরের সংখ্যা (frequency) সমান হয়। এই "frequency" বা "count" বের করার জন্যই আমরা বিভিন্ন অ্যাপ্রোচ ব্যবহার করব।

### **Approach 1: Sorting**

এটা সবচেয়ে সহজ এবং প্রথম যে চিন্তা মাথায় আসে। যদি দুটি স্ট্রিং অ্যানাগ্রাম হয়, তাহলে তাদের অক্ষরগুলোকে বর্ণানুক্রমিকভাবে (alphabetically) সাজালে (sort করলে) দুটি স্ট্রিং একই হয়ে যাবে।

**Steps:**
1.  **Initial Check:** প্রথমে চেক করুন দুটি স্ট্রিং-এর দৈর্ঘ্য (length) সমান কি না। যদি দৈর্ঘ্য সমান না হয়, তাহলে তারা কখনই অ্যানাগ্রাম হতে পারবে না। সরাসরি `false` রিটার্ন করুন।
2.  **সর্ট করুন (Sort):** `s` এবং `t` উভয় স্ট্রিং-কে সর্ট করুন।
3.  **তুলনা করুন (Compare):** সর্ট করা স্ট্রিং দুটিকে তুলনা করুন। যদি তারা সমান হয়, তাহলে মূল স্ট্রিং দুটি অ্যানাগ্রাম।

**Python Code:**
```python
def isAnagram_sorting(s: str, t: str) -> bool:
    # Step 1: Check if lengths are different. If so, they can't be anagrams.
    if len(s) != len(t):
        return False
    
    # Step 2 & 3: Sort both strings and compare them.
    # sorted() function returns a sorted list of characters.
    # For example, sorted("anagram") -> ['a', 'a', 'a', 'g', 'm', 'n', 'r']
    return sorted(s) == sorted(t)
```

**Complexity Analysis:**
*   **Time Complexity: O(N log N)**
    *   এখানে প্রধান কাজ হলো স্ট্রিং সর্ট করা। একটি N দৈর্ঘ্যের স্ট্রিং সর্ট করতে O(N log N) সময় লাগে। Python-এর `sorted()` ফাংশন Timsort ব্যবহার করে, যার গড় এবং সবচেয়ে খারাপ ক্ষেত্রে টাইম কমপ্লেক্সিটি O(N log N)।
*   **Space Complexity: O(N)**
    *   `sorted()` ফাংশনটি একটি নতুন লিস্ট তৈরি করে যেখানে সর্ট করা অক্ষরগুলো থাকে। তাই, অতিরিক্ত O(N) স্পেস প্রয়োজন হয়। কিছু ভাষায় (যেমন C++) স্ট্রিংকে in-place সর্ট করা যায়, কিন্তু Python-এ স্ট্রিংগুলো immutable হওয়ায় নতুন স্পেস ব্যবহার করতেই হয়।

---

### **Approach 2: Hash Map / Frequency Counter**

এটি একটি আরও কার্যকর (efficient) সমাধান এবং ইন্টারভিউতে এই অ্যাপ্রোচটিই বেশি আশা করা হয়। এখানে আমরা প্রতিটি স্ট্রিং-এর অক্ষরের সংখ্যা গণনা করব এবং তারপর সেই সংখ্যাগুলো তুলনা করব।

**Steps:**
1.  **Initial Check:** আগের মতোই, প্রথমে স্ট্রিং-এর দৈর্ঘ্য চেক করুন। সমান না হলে `false` রিটার্ন করুন।
2.  **Build Frequency Map:** একটি হ্যাশ ম্যাপ (Python-এ ডিকশনারি) নিন।
    *   প্রথম স্ট্রিং `s`-এর উপর দিয়ে যান এবং প্রতিটি অক্ষরের জন্য তার count বা সংখ্যা ম্যাপে বাড়াতে থাকুন।
    *   এবার দ্বিতীয় স্ট্রিং `t`-এর উপর দিয়ে যান এবং প্রতিটি অক্ষরের জন্য তার count ম্যাপ থেকে কমাতে থাকুন।
3.  **Check the Map:** এখন ম্যাপের সমস্ত ভ্যালু চেক করুন। যদি সব অক্ষরের count শূন্য (0) হয়, তার মানে দুটি স্ট্রিং-এ প্রতিটি অক্ষর সমান সংখ্যায় ছিল। অর্থাৎ, তারা অ্যানাগ্রাম। যদি কোনো count শূন্য না হয়, তবে তারা অ্যানাগ্রাম নয়।

**Python Code:**
```python
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

# A more "Pythonic" way using collections.Counter
from collections import Counter

def isAnagram_pythonic(s: str, t: str) -> bool:
    # Counter creates a hash map of character counts automatically.
    # Counter("anagram") -> {'a': 3, 'n': 1, 'g': 1, 'r': 1, 'm': 1}
    # Two Counter objects are equal if their keys and counts are the same.
    return Counter(s) == Counter(t)

```

**Complexity Analysis:**
*   **Time Complexity: O(N)**
    *   আমরা `s` স্ট্রিং-এর উপর দিয়ে একবার (O(N)) এবং `t` স্ট্রিং-এর উপর দিয়ে একবার (O(N)) যাই। হ্যাশ ম্যাপে প্রতিটি অপারেশন (যোগ, বিয়োগ, অ্যাক্সেস) গড়ে O(1) সময় নেয়। সুতরাং মোট সময় O(N) + O(N) = O(N)।
*   **Space Complexity: O(1) or O(k)**
    *   আমরা একটি হ্যাশ ম্যাপ ব্যবহার করছি। যদি অক্ষরের সেট সীমিত হয় (যেমন, শুধুমাত্র 26টি ছোট হাতের ইংরেজি অক্ষর), তাহলে ম্যাপের আকার কখনই 26-এর বেশি হবে না। তাই স্পেস কমপ্লেক্সিটি **O(1)** (ধ্রুবক)।
    *   যদি যেকোনো ইউনিকোড অক্ষর আসতে পারে, তাহলে স্পেস কমপ্লেক্সিটি হবে O(k), যেখানে `k` হলো ইউনিক অক্ষরের সংখ্যা। তবে এই প্রবলেমের ক্ষেত্রে সাধারণত O(1) ধরা হয়।

---

### **Summary**

| Approach              | Time Complexity | Space Complexity | Notes                                                              |
| --------------------- | --------------- | ---------------- | ------------------------------------------------------------------ |
| **Sorting**           | O(N log N)      | O(N)             | সহজবোধ্য, কিন্তু কম কার্যকর (less efficient)।                       |
| **Hash Map / Counter**| O(N)            | O(1)             | সবচেয়ে কার্যকর (most efficient) এবং ইন্টারভিউয়ের জন্য সেরা অ্যাপ্রোচ। |

**কোনটি ব্যবহার করবেন?**
ইন্টারভিউতে আপনাকে প্রথমে সর্টিং অ্যাপ্রোচটির কথা বলতে পারেন কারণ এটি সহজ। তারপর অপ্টিমাইজেশন হিসেবে হ্যাশ ম্যাপ অ্যাপ্রোচটির কথা বলবেন, এবং এর টাইম কমপ্লেক্সিটি কেন ভালো (O(N) vs O(N log N)) তা ব্যাখ্যা করবেন। এটি আপনার সমস্যা সমাধানের দক্ষতা এবং অপ্টিমাইজ করার ক্ষমতা প্রমাণ করবে।