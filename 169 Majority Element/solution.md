### **Problem Statement**

তোমাকে `n` সাইজের একটি ইন্টিজার অ্যারে `nums` দেওয়া হবে। তোমার কাজ হলো **majority element** খুঁজে বের করা।

**Majority Element কী?** Majority element হলো সেই উপাদান যা অ্যারেতে **`floor(n / 2)`-এর চেয়ে বেশি বার** আসে।

**Important:** তুমি ধরে নিতে পারো যে অ্যারেটি খালি নয় এবং majority element **সবসময়ই** বিদ্যমান থাকবে।

**Example-01:**
*   `nums = [3, 2, 3]`
*   `n = 3`, `floor(3 / 2) = 1`। `3` দুইবার এসেছে, যা `1`-এর চেয়ে বেশি।
*   **Resut:** `3`

**Example-02:**
*   `nums = [2, 2, 1, 1, 1, 2, 2]`
*   `n = 7`, `floor(7 / 2) = 3`। `2` চারবার এসেছে, যা `3`-এর চেয়ে বেশি।
*   **Result:** `2`

### **The Core Challenge**

এই সমস্যার একাধিক সমাধান আছে, যার প্রত্যেকটির টাইম এবং স্পেস কমপ্লেক্সিটির মধ্যে একটি ট্রেড-অফ রয়েছে। মূল চ্যালেঞ্জ হলো একটি এমন সমাধান খুঁজে বের করা যা লিনিয়ার টাইমে (O(N)) এবং কনস্ট্যান্ট স্পেসে (O(1)) কাজ করে।

---

### **Approach 1: Brute Force**

এটি সবচেয়ে সহজবোধ্য কিন্তু সবচেয়ে অদক্ষ পদ্ধতি।

**Core Idea:**
প্রতিটি উপাদানের জন্য, পুরো অ্যারে জুড়ে লুপ চালিয়ে তার ফ্রিকোয়েন্সি গণনা করো। যদি কোনো উপাদানের ফ্রিকোয়েন্সি `n / 2`-এর চেয়ে বেশি হয়, তবে সেটিই উত্তর।

**C++ Code:**
```cpp
#include <iostream>
#include <vector>

int majorityElement_brute_force(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] == nums[i]) {
                count++;
            }
        }
        if (count > n / 2) {
            return nums[i];
        }
    }
    return -1; // Should not happen based on problem statement
}
```

**Complexity Analysis:**
*   **Time Complexity: O(N²):** দুটি নেস্টেড লুপের কারণে টাইম কমপ্লেক্সিটি কোয়াড্রেটিক।
*   **Space Complexity: O(1):** কোনো অতিরিক্ত স্পেস ব্যবহার করা হয়নি।

**Verdict:** খুবই অদক্ষ। বড় ইনপুটের জন্য LeetCode-এ "Time Limit Exceeded" (TLE) দেবে।

---

### **Approach 2: Hash Map (Frequency Counting)**

এটি একটি খুবই সাধারণ এবং কার্যকর সমাধান, যা ফ্রিকোয়েন্সি কাউন্টিং সমস্যার জন্য প্রায়ই ব্যবহৃত হয়।

**Core idea:**
একটি হ্যাশ ম্যাপ (`unordered_map`) ব্যবহার করে প্রতিটি উপাদানের ফ্রিকোয়েন্সি গণনা এবং সংরক্ষণ করো।

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

int majorityElement_hash_map(vector<int>& nums) {
    unordered_map<int, int> counts;
    int n = nums.size();

    for (int num : nums) {
        counts[num]++;
        if (counts[num] > n / 2) {
            return num;
        }
    }
    return -1; // Should not happen
}
```

**Complexity Analysis:**
*   **Time Complexity: O(N):** আমরা অ্যারেটি একবার মাত্র ট্র্যাভার্স করি। হ্যাশ ম্যাপে প্রতিটি অপারেশন গড়ে O(1) সময় নেয়।
*   **Space Complexity: O(N):** সবচেয়ে খারাপ ক্ষেত্রে, যদি `n/2` টি ইউনিক উপাদান থাকে, তবে ম্যাপের আকার O(N) হতে পারে।

**Verdict:** এটি একটি ভালো এবং কার্যকর সমাধান, কিন্তু এটি অতিরিক্ত স্পেস ব্যবহার করে।

---

### **Approach 3: Sorting**

এটি একটি চতুর এবং সংক্ষিপ্ত সমাধান, যা অ্যারে সর্ট করার বৈশিষ্ট্যের উপর নির্ভর করে।

**Core idea:**
যদি একটি উপাদান অ্যারের অর্ধেকেরও বেশি জায়গা দখল করে, তাহলে অ্যারেটিকে সর্ট করার পর সেই উপাদানটি **অবশ্যই** অ্যারের মাঝখানে (`n / 2`-তম ইনডেক্সে) থাকবে।

**C++ Code:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int majorityElement_sorting(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}
```

**Complexity Analysis:**
*   **Time Complexity: O(N log N):** `sort` ফাংশনের টাইম কমপ্লেক্সিটি O(N log N)।
*   **Space Complexity: O(1) or O(log N):** `sort` সাধারণত Introsort ব্যবহার করে, যা একটি ইন-প্লেস সর্ট। এর জন্য রিকার্সন স্ট্যাকের কারণে O(log N) স্পেস লাগতে পারে।

**Verdict:** খুবই সংক্ষিপ্ত এবং চতুর সমাধান, কিন্তু টাইম কমপ্লেক্সিটি হ্যাশ ম্যাপ পদ্ধতির চেয়ে বেশি।

---

### **Approach 4: Boyer-Moore Voting Algorithm (Best Solution)**

এটিই **Best Solution**। এটি লিনিয়ার টাইমে এবং কনস্ট্যান্ট স্পেসে কাজ করে।

**Core idea:**
অ্যালগরিদমটি একটি খুব সহজ ধারণার উপর ভিত্তি করে তৈরি: majority element-এর প্রতিটি occurrence-কে `+1` এবং অন্য যেকোনো উপাদানের occurrence-কে `-1` হিসেবে ধরলে, সবশেষে যোগফল অবশ্যই ধনাত্মক হবে। এই অ্যালগরিদমটি একজন "প্রার্থী" (`candidate`) এবং একটি "ভোট" (`count`) ট্র্যাক করে এই ধারণাটিকে কাজে লাগায়।

**C++ Code:**
```cpp
#include <iostream>
#include <vector>

int majorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }

        if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}
```

**Complexity Analysis:**
*   **Time Complexity: O(N):** আমরা অ্যারেটি একবার মাত্র ট্র্যাভার্স করি।
*   **Space Complexity: O(1):** আমরা শুধুমাত্র দুটি ভেরিয়েবল (`candidate`, `count`) ব্যবহার করেছি।

**Verdict:** এটিই **Best Solution**, যা টাইম এবং স্পেস উভয় দিক থেকেই সবচেয়ে কার্যকর।

#### **Approach-4: Dry Run (`nums = [2, 2, 1, 1, 1, 2, 2]`)**

| `num` | `count` (শুরুতে) | `candidate` (শুরুতে) | Action | `count` (শেষে) | `candidate` (শেষে) |
|---|---|---|---|---|---|
| 2 | 0 | 0 | `count=0`, `candidate=2`. `num==candidate`, `count++` | 1 | 2 |
| 2 | 1 | 2 | `num==candidate`, `count++` | 2 | 2 |
| 1 | 2 | 2 | `num!=candidate`, `count--` | 1 | 2 |
| 1 | 1 | 2 | `num!=candidate`, `count--` | 0 | 2 |
| 1 | 0 | 2 | `count=0`, `candidate=1`. `num==candidate`, `count++` | 1 | 1 |
| 2 | 1 | 1 | `num!=candidate`, `count--` | 0 | 1 |
| 2 | 0 | 1 | `count=0`, `candidate=2`. `num==candidate`, `count++` | 1 | 2 |

**Final Result:** লুপ শেষে `candidate` হলো `2`।

---

### **Summary of Approaches**

| Approach  | Time Complexity | Space Complexity | Verdict |
| :--- | :--- | :--- | :--- |
| **Brute Force** | O(N²) | O(1) | সহজবোধ্য কিন্তু অদক্ষ। TLE দেবে। |
| **Hash Map** | O(N) | O(N) | কার্যকর এবং সাধারণ, কিন্তু অতিরিক্ত স্পেস ব্যবহার করে। |
| **Sorting** | O(N log N) | O(1) / O(log N) | চতুর এবং সংক্ষিপ্ত, কিন্তু টাইম কমপ্লেক্সিটি সেরা নয়। |
| **Boyer-Moore Voting** | **O(N)** | **O(1)** | **সর্বোত্তম সমাধান।** কার্যকর, দ্রুত এবং স্পেস-এফিসিয়েন্ট। |