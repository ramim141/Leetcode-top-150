### **Problem Statement**

তোমাকে দুটি স্ট্রিং `s` এবং `t` দেওয়া হবে। তোমার কাজ হলো `s` স্ট্রিংটি `t`-এর একটি **subsequence (উপঅনুক্রম)** কি না, তা নির্ধারণ করা।

**Subsequence কী?** একটি subsequence হলো একটি নতুন স্ট্রিং যা মূল স্ট্রিং থেকে কিছু অক্ষর (বা কোনো অক্ষরই নয়) মুছে দিয়ে তৈরি করা হয়, কিন্তু বাকি অক্ষরগুলোর আপেক্ষিক ক্রম (relative order) অপরিবর্তিত থাকে।

**Example:**
*   `s = "abc"`, `t = "ahbgdc"` -> **True**
*   `s = "axc"`, `t = "ahbgdc"` -> **False**

---

### **Approach 1: Two Pointers (Greedy Approach - Best and Most Common Solution)**

এটিই সেরা, সবচেয়ে সহজবোধ্য এবং ইন্টারভিউয়ের জন্য উপযুক্ত সমাধান।

**Core Idea:**
আমরা দুটি পয়েন্টার ব্যবহার করব: `i` (`s`-এর জন্য) এবং `j` (`t`-এর জন্য)। আমরা `t` স্ট্রিং-এর উপর দিয়ে `j` পয়েন্টারটি সরাতে থাকব। যখনই `s[i]` এবং `t[j]` ম্যাচ করবে, আমরা `i` পয়েন্টারটিকেও এক ঘর এগিয়ে দেব।

**Algorithm:**
1.  দুটি পয়েন্টার `i = 0` (`s`-এর জন্য) এবং `j = 0` (`t`-এর জন্য) নাও।
2.  যতক্ষণ `i < s.length()` এবং `j < t.length()` থাকে, ততক্ষণ একটি `while` লুপ চালাও।
3.  যদি `s[i] == t[j]` হয়, `i`-কে এক ঘর এগিয়ে দাও (`i++`)।
4.  ম্যাচ হোক বা না হোক, `j` পয়েন্টারটিকে সবসময়ই এক ঘর এগিয়ে দিতে হবে (`j++`)।
5.  লুপ শেষে, যদি `i`-এর মান `s.length()`-এর সমান হয়, তার মানে আমরা `s`-এর সব অক্ষর খুঁজে পেয়েছি।

**C++ Code:**
```cpp
#include <iostream>
#include <string>

bool isSubsequence_two_pointers(string s, string t) {
    int i = 0; // Pointer for s
    int j = 0; // Pointer for t

    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return i == s.length();
}
```
**Complexity Analysis:**
*   **Time Complexity: O(|t|)**, যেখানে `|t|` হলো `t` স্ট্রিং-এর দৈর্ঘ্য।
*   **Space Complexity: O(1)**।

---

### **Approach 2: Using Built-in `string::find`**

এই পদ্ধতিতে আমরা C++ এর বিল্ট-ইন ফাংশন ব্যবহার করি, যা কোডকে সংক্ষিপ্ত করে কিন্তু টাইম কমপ্লেক্সিটি বেশি হতে পারে।

**Core Idea:**
আমরা `s`-এর প্রতিটি অক্ষরকে `t`-তে ক্রমানুসারে খুঁজব। প্রতিটি অক্ষর খুঁজে পাওয়ার পর, পরবর্তী সার্চ সেই পাওয়া পজিশনের পর থেকে শুরু করব।

**Algorithm:**
1.  `t`-তে সার্চের জন্য একটি `start_pos = 0` রাখো।
2.  `s`-এর প্রতিটি অক্ষর `c`-এর জন্য লুপ চালাও।
3.  `t.find(c, start_pos)` ব্যবহার করে `c`-কে খোঁজো।
4.  যদি খুঁজে পাওয়া না যায় (`string::npos`), `false` রিটার্ন করো।
5.  যদি পাওয়া যায় (ইনডেক্স `found_pos`), `start_pos`-কে `found_pos + 1`-এ আপডেট করো।
6.  লুপ শেষে `true` রিটার্ন করো।

**C++ Code:**
```cpp
#include <iostream>
#include <string>

bool isSubsequence_builtin(string s, string t) {
    size_t start_pos = 0;

    for (char c : s) {
        size_t found_pos = t.find(c, start_pos);
        if (found_pos == string::npos) {
            return false;
        }
        start_pos = found_pos + 1;
    }
    
    return true;
}
```
**Complexity Analysis:**
*   **Time Complexity: O(|s| * |t|)** (worst-case)।
*   **Space Complexity: O(1)**।

---

### **Approach 3: Dynamic Programming (Tabulation)**

এটি একটি বটম-আপ ডাইনামিক প্রোগ্রামিং সমাধান। যদিও এই সমস্যার জন্য এটি Overkill, তবে এটি Longest Common Subsequence (LCS) সমস্যার একটি সহজ সংস্করণ এবং DP শেখার জন্য চমৎকার।

**Core Idea:**
আমরা একটি 2D `dp` টেবিল তৈরি করব, যেখানে `dp[i][j]` হবে `s` স্ট্রিং-এর প্রথম `i`টি অক্ষর এবং `t` স্ট্রিং-এর প্রথম `j`টি অক্ষরের মধ্যে দীর্ঘতম সাধারণ উপঅনুক্রমের (Longest Common Subsequence) দৈর্ঘ্য।

যদি শেষে `dp[s.length()][t.length()]`-এর মান `s.length()`-এর সমান হয়, তার মানে `s` `t`-এর একটি subsequence।

**Algorithm:**
1.  `m = s.length()`, `n = t.length()`।
2.  `(m+1) x (n+1)` সাইজের একটি `dp` টেবিল তৈরি করো, সব মান `0` দিয়ে শুরু করো।
3.  দুটি নেস্টেড লুপ চালাও: `i` 1 থেকে `m` পর্যন্ত এবং `j` 1 থেকে `n` পর্যন্ত।
4.  **Core Logic:**
    *   **যদি `s[i-1] == t[j-1]` হয়:** `dp[i][j] = 1 + dp[i-1][j-1]`।
    *   **যদি `s[i-1] != t[j-1]` হয়:** `dp[i][j] = dp[i][j-1]` (কারণ আমরা `t`-এর অক্ষর বাদ দিতে পারি, কিন্তু `s`-এর নয়)।
5.  লুপ শেষে `dp[m][n] == m` চেক করো।

**C++ Code:**
```cpp
#include <iostream>
#include <string>
#include <vector>

bool isSubsequence_dp(string s, string t) {
    int m = s.length();
    int n = t.length();

    if (m == 0) return true;
    if (n < m) return false;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[m][n] == m;
}
```
**Complexity Analysis:**
*   **Time Complexity: O(|s| * |t|)**।
*   **Space Complexity: O(|s| * |t|)**। (এটি O(|t|) স্পেসে অপ্টিমাইজ করা যায়)।

---

### **Approach 4: Follow-up (Preprocessing for Many `s` Queries)**

যদি `s`-এর অনেকগুলো সংস্করণ (S1, S2, ... Sk) থাকে এবং একটিই বড় `t` থাকে, তাহলে `t`-কে প্রি-প্রসেস করাটা সবচেয়ে কার্যকর।

**Core Idea:**
`t`-এর প্রতিটি অক্ষরের জন্য তার ইনডেক্সগুলোর একটি সর্টেড লিস্ট তৈরি করে রাখি। তারপর প্রতিটি `s`-এর জন্য, আমরা `t`-কে ট্র্যাভার্স না করে এই ম্যাপ এবং বাইনারি সার্চ ব্যবহার করে দ্রুত সমাধান করি।

**Algorithm:**
1.  **Preprocessing (O(|t|)):**
    *   একটি হ্যাশ ম্যাপ `map<char, vector<int>> indices` তৈরি করো।
    *   `t`-এর উপর দিয়ে একবার লুপ চালিয়ে প্রতিটি অক্ষরের জন্য তার ইনডেক্সগুলো ম্যাপে যোগ করো।
2.  **Querying (O(|s| * log|t|)):**
    *   প্রতিটি `s`-এর জন্য:
        *   `last_index = -1` দিয়ে শুরু করো।
        *   `s`-এর প্রতিটি অক্ষর `c`-এর জন্য:
            *   ম্যাপ থেকে `c`-এর ইনডেক্স লিস্টটি নাও।
            *   এই লিস্টে, `last_index`-এর চেয়ে বড় প্রথম ইনডেক্সটি বাইনারি সার্চ (`upper_bound`) দিয়ে খুঁজে বের করো।
            *   যদি এমন কোনো ইনডেক্স না পাওয়া যায়, `false` রিটার্ন করো।
            *   নাহলে, `last_index`-কে নতুন পাওয়া ইনডেক্সে আপডেট করো।
        *   লুপ শেষে `true` রিটার্ন করো।

**C++ Code (Conceptual):**
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 

class SubsequenceChecker {
private:
    map<char, vector<int>> indices;

public:
    SubsequenceChecker(const string& t) {
        for (int i = 0; i < t.length(); ++i) {
            indices[t[i]].push_back(i);
        }
    }

    bool isSubsequence(const string& s) {
        int last_index = -1;
        for (char c : s) {
            if (indices.find(c) == indices.end()) {
                return false;
            }

            auto& idx_list = indices[c];
            auto it = upper_bound(idx_list.begin(), idx_list.end(), last_index);

            if (it == idx_list.end()) {
                return false;
            }
            last_index = *it;
        }
        return true;
    }
};
```
**Complexity Analysis (Follow-up):**
*   **Time Complexity:** Preprocessing: O(|t|). Each query: O(|s| * log|t|).
*   **Space Complexity:** O(|t|).

---

### **সারসংক্ষেপ (Summary of Approaches)**

| Approach  | Time Complexity | Space Complexity | Use Case  |
| :--- | :--- | :--- | :--- |
| **Two Pointers** | **O(|t|)** | **O(1)** | **সাধারণ এবং একক ক্যোয়ারির জন্য সর্বোত্তম।** |
| **Built-in `find`** | O(|s| * |t|) | O(1) | দ্রুত কোডিং করার জন্য, কিন্তু অদক্ষ। |
| **Dynamic Programming**| O(|s|*|t|) | O(|s|*|t|) | DP অনুশীলনের জন্য, অথবা LCS-এর মতো সম্পর্কিত সমস্যার জন্য। |
| **Preprocessing** | O(|t| + K*|s|*log|t|) | O(|t|) | **যখন একটি `t`-এর বিপরীতে অনেকগুলো `s` চেক করতে হয়।** |