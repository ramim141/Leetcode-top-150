---

### **Problem Statement**

তোমাকে একটি ইন্টিজার অ্যারে `nums` এবং একটি নন-নেগেটিভ ইন্টিজার `k` দেওয়া হবে। তোমার কাজ হলো অ্যারেটিকে **ডানদিকে (right)** `k` ধাপ **rotate** করা।

**গুরুত্বপূর্ণ শর্ত:** তোমাকে এই কাজটি **ইন-প্লেস (in-place)** করতে হবে, অর্থাৎ কোনো অতিরিক্ত অ্যারে ব্যবহার না করে এবং O(1) অতিরিক্ত স্পেস ব্যবহার করে।

**উদাহরণ ১:**
*   `nums = [1, 2, 3, 4, 5, 6, 7]`, `k = 3`
*   **ডানদিকে ১ ধাপ:** `[7, 1, 2, 3, 4, 5, 6]`
*   **ডানদিকে ২ ধাপ:** `[6, 7, 1, 2, 3, 4, 5]`
*   **ডানদিকে ৩ ধাপ:** `[5, 6, 7, 1, 2, 3, 4]`
*   **ফলাফল:** `[5, 6, 7, 1, 2, 3, 4]`

**উদাহরণ ২:**
*   `nums = [-1, -100, 3, 99]`, `k = 2`
*   **ফলাফল:** `[3, 99, -1, -100]`

### **মূল চ্যালেঞ্জ এবং এজ কেস (Key Challenges & Edge Cases)**

1.  **In-place Requirement:** এটাই মূল চ্যালেঞ্জ। O(N) স্পেস ব্যবহার করে সমাধান করা সহজ, কিন্তু O(1) স্পেসে করাটা একটু কৌশলী।
2.  **`k`-এর মান:** `k`-এর মান অ্যারের দৈর্ঘ্যের (`n`) চেয়ে বড় হতে পারে। যেমন, ৭ দৈর্ঘ্যের একটি অ্যারে ৭ বার rotate করলে আগের অবস্থাতেই ফিরে আসে। তাই, `k = 10` বার rotate করা আর `k = 3` বার rotate করা একই কথা (`10 % 7 = 3`)। সুতরাং, আমাদের আসল `k` হবে `k % n`।

---

### **Approach 1: Brute Force (Simulation)**

এটি সবচেয়ে সহজবোধ্য পদ্ধতি, যেখানে আমরা সমস্যাটিকে আক্ষরিক অর্থে সিমুলেট করি। আমরা অ্যারেটিকে ১ ধাপ করে `k` বার rotate করব।

**Core Concept:**
একটি লুপ `k` বার চালাও। প্রতিটি ইটারেশনে, অ্যারের শেষ উপাদানটিকে তুলে এনে সামনে বসিয়ে দাও।

**Algorithm Steps:**
1.  প্রথমে, `k = k % len(nums)` করে `k`-এর মান ঠিক করে নাও।
2.  একটি `for` লুপ `k` বার চালাও।
3.  লুপের ভেতরে:
    *   `nums.pop()` ব্যবহার করে শেষ উপাদানটি (`previous`) বের করে নাও।
    *   `nums.insert(0, previous)` ব্যবহার করে সেই উপাদানটিকে অ্যারের শুরুতে যোগ করো।

**Python Code:**
```python
def rotate_brute_force(nums: list[int], k: int):
    n = len(nums)
    k %= n  # k-এর মান ঠিক করা
    
    for _ in range(k):
        previous = nums.pop() # শেষ উপাদানটি O(1) সময়ে বের করা
        nums.insert(0, previous) # শুরুতে যোগ করা O(N) সময় নেয়
```

**Complexity Analysis:**
*   **Time Complexity: O(N * k):** আমরা `k` বার লুপ চালাই, এবং প্রতিটি লুপের ভেতরে `insert(0, ...)` অপারেশনটি অ্যারের সব উপাদানকে এক ঘর ডানে সরাতে O(N) সময় নেয়। তাই মোট সময় O(N*k)।
*   **Space Complexity: O(1):** আমরা কোনো অতিরিক্ত অ্যারে ব্যবহার করছি না।

**Verdict:** এটি খুবই ধীর এবং বড় ইনপুটের জন্য LeetCode-এ "Time Limit Exceeded" (TLE) দেবে।

#### **Approach-1: Dry Run (`nums = [1,2,3,4], k = 2`)**
1.  **start:** `nums = [1, 2, 3, 4]`
2.  **First Rotation (i=0):**
    *   `previous = nums.pop()` -> `4`। `nums` এখন `[1, 2, 3]`।
    *   `nums.insert(0, 4)`। `nums` এখন `[4, 1, 2, 3]`।
3.  **Second Rotation (i=1):**
    *   `previous = nums.pop()` -> `3`। `nums` এখন `[4, 1, 2]`।
    *   `nums.insert(0, 3)`। `nums` এখন `[3, 4, 1, 2]`।
4.  **Result:** `[3, 4, 1, 2]`।

---

### **Approach 2: Using an Extra Array**

এই পদ্ধতিতে আমরা `in-place` শর্তটি উপেক্ষা করে একটি সহজ সমাধান তৈরি করি। এটি একটি ভালো মধ্যবর্তী ধাপ।

**Core Concept:**
একটি নতুন অ্যারে তৈরি করো। মূল অ্যারের প্রতিটি উপাদান `nums[i]`-কে তার নতুন পজিশন `(i + k) % n`-এ নতুন অ্যারেতে রাখো। শেষে, নতুন অ্যারেটিকে মূল অ্যারেতে কপি করে দাও।

**Python Code:**
```python
def rotate_extra_array(nums: list[int], k: int):
    n = len(nums)
    k %= n
    
    # নতুন অ্যারে তৈরি
    result = [0] * n
    
    for i in range(n):
        new_index = (i + k) % n
        result[new_index] = nums[i]
        
    # ফলাফল মূল অ্যারেতে কপি করা
    # nums[:] is crucial for in-place modification
    nums[:] = result
```

**Complexity Analysis:**
*   **Time Complexity: O(N):** আমরা একবার লুপ চালিয়ে `result` অ্যারে তৈরি করি (O(N)) এবং একবার `nums` অ্যারেতে কপি করি (O(N))। মোট O(N)।
*   **Space Complexity: O(N):** `result` অ্যারের জন্য আমাদের অতিরিক্ত O(N) স্পেস প্রয়োজন।

#### **Approach-2: Dry Run (`nums = [1,2,3,4,5], k = 2`)**
1.  **Initialization:** `n=5`, `k=2`, `result = [0,0,0,0,0]`
2.  **i = 0:** `new_index = (0+2)%5 = 2`. `result[2] = nums[0] = 1`. `result = [0,0,1,0,0]`
3.  **i = 1:** `new_index = (1+2)%5 = 3`. `result[3] = nums[1] = 2`. `result = [0,0,1,2,0]`
4.  **i = 2:** `new_index = (2+2)%5 = 4`. `result[4] = nums[2] = 3`. `result = [0,0,1,2,3]`
5.  **i = 3:** `new_index = (3+2)%5 = 0`. `result[0] = nums[3] = 4`. `result = [4,0,1,2,3]`
6.  **i = 4:** `new_index = (4+2)%5 = 1`. `result[1] = nums[4] = 5`. `result = [4,5,1,2,3]`
7.  **Final Copy:** `nums[:] = [4, 5, 1, 2, 3]`.

---

### **Approach 3: The Reversal Algorithm (The Best Solution)**

এটি একটি অত্যন্ত চতুর এবং কার্যকর O(1) স্পেস সমাধান, যা ইন্টারভিউতে সবচেয়ে বেশি প্রশংসিত হয়।

**Core Concept:**
এই পদ্ধতিটি তিনটি ধাপে কাজ করে, যেখানে আমরা অ্যারের বিভিন্ন অংশকে উল্টে দিই (reverse)।
1.  **ধাপ ১: পুরো অ্যারেটিকে উল্টে দাও (Reverse the whole array)।**
2.  **ধাপ ২: প্রথম `k`টি উপাদানকে উল্টে দাও (Reverse the first `k` elements)।**
3.  **ধাপ ৩: বাকি `n-k`টি উপাদানকে উল্টে দাও (Reverse the remaining `n-k` elements)।**

**Python Code:**
```python

def rotate_reversal(nums: list[int], k: int):
    n = len(nums)
    k %= n
    
    if k == 0:
        return
        
    # ধাপ ১: পুরো অ্যারে উল্টানো
    nums.reverse()
    
    # ধাপ ২: প্রথম k টি উপাদান উল্টানো
    nums[:k] = nums[:k][::-1]
    
    # ধাপ ৩: বাকি n-k টি উপাদান উল্টানো
    nums[k:] = nums[k:][::-1]
```


**Complexity Analysis:**
*   **Time Complexity: O(N):** প্রথম ধাপে Nটি উপাদান, দ্বিতীয় ধাপে kটি, এবং তৃতীয় ধাপে n-kটি উপাদান প্রসেস হয়। মোট অপারেশন `N + k + (n-k) = 2N`-এর সমানুপাতিক, যা O(N)।
*   **Space Complexity: O(1):** আমরা কোনো অতিরিক্ত অ্যারে ব্যবহার করিনি। `reverse` ফাংশনটি ইন-প্লেস কাজ করে।

#### **Approach-3: Dry Run (`nums = [1,2,3,4,5,6,7], k = 3`)**
1.  **শুরুতে:** `nums = [1, 2, 3, 4, 5, 6, 7]`
2.  **ধাপ ১ (পুরোটা উল্টানো):**
    *   `reverse(nums, 0, 6)`
    *   `nums` এখন: `[7, 6, 5, 4, 3, 2, 1]`
3.  **ধাপ ২ (প্রথম k=3টি উল্টানো):**
    *   `reverse(nums, 0, 2)`
    *   `nums` এখন: `[5, 6, 7, 4, 3, 2, 1]`
4.  **ধাপ ৩ (বাকি n-k=4টি উল্টানো):**
    *   `reverse(nums, 3, 6)`
    *   `nums` এখন: `[5, 6, 7, 1, 2, 3, 4]`
5.  **Result:** `[5, 6, 7, 1, 2, 3, 4]`। এটিই সঠিক উত্তর!

---

### **Summary of Approaches**

| Approach | Time Complexity | Space Complexity | Verdict  |
| :--- | :--- | :--- | :--- |
| **Brute Force** | O(N * k) | O(1) | সহজবোধ্য, কিন্তু অদক্ষ। TLE দেবে। |
| **Extra Array** | O(N) | O(N) | কার্যকর, কিন্তু `in-place` শর্ত পূরণ করে না। |
| **Reversal Algorithm** | **O(N)** | **O(1)** | **সর্বোত্তম সমাধান।** কার্যকর, দ্রুত এবং স্পেস-এফিসিয়েন্ট। ইন্টারভিউয়ের জন্য সেরা। |