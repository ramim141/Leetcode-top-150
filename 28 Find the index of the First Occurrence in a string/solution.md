### **Problem Statement:**

তোমাকে দুটি স্ট্রিং `haystack` এবং `needle` দেওয়া হবে। তোমার কাজ হলো `haystack`-এর মধ্যে `needle`-এর প্রথম occurrence-এর ইনডেক্স খুঁজে বের করা।

যদি `needle` `haystack`-এর অংশ না হয়, তাহলে `-1` রিটার্ন করতে হবে। যদি `needle` একটি খালি স্ট্রিং `""` হয়, তাহলে `0` রিটার্ন করতে হবে।

**Example:**
*   `haystack = "sadbutsad"`, `needle = "sad"` -> **0** (কারণ "sad" ইনডেক্স 0 থেকে শুরু হয়)
*   `haystack = "leetcode"`, `needle = "leeto"` -> **-1** (কারণ "leeto" এর অংশ নয়)
*   `haystack = "hello"`, `needle = ""` -> **0** (বিশেষ শর্ত অনুযায়ী)

### **Core Challenges & Idea**

1.  **Substring Matching:** মূল চ্যালেঞ্জ হলো `haystack`-এর প্রতিটি সম্ভাব্য পজিশন থেকে `needle`-কে মেলানোর চেষ্টা করা।
2.  **Efficiency:** ব্রুট-ফোর্স পদ্ধতি সহজবোধ্য, কিন্তু এটি অদক্ষ হতে পারে। ইন্টারভিউয়াররা প্রায়ই এর সীমাবদ্ধতা এবং আরও উন্নত অ্যালগরিদম (যেমন, KMP) সম্পর্কে জিজ্ঞাসা করেন।
3.  **Edge Cases:**
    *   `needle`-এর দৈর্ঘ্য `haystack`-এর চেয়ে বেশি।
    *   `needle` খালি স্ট্রিং।
    *   `haystack` খালি স্ট্রিং।

---

### **Approach 1: Using Library Functions (Cheating/Easy Way)**

বাস্তব জীবনে, আপনি প্রায়শই বিল্ট-ইন ফাংশন ব্যবহার করবেন। এটি জানা ভালো, কিন্তু ইন্টারভিউতে আপনাকে এটি ছাড়া ইমপ্লিমেন্ট করতে বলা হবে।

**C++ Code:**
```cpp

int strStr_library(string haystack, string needle) {
    if (needle.empty()) {
        return 0;
    }
    size_t found_pos = haystack.find(needle);
    if (found_pos != string::npos) {
        return (int)found_pos;
    }
    return -1;
}
```

**Verdict:** এটি সমস্যার সমাধান করে, কিন্তু ইন্টারভিউতে এটি গ্রহণ করা হবে না।

---

### **Approach 2: Brute Force (Sliding Window)**

এটিই সবচেয়ে স্বজ্ঞাত এবং সরাসরি ইমপ্লিমেন্টেশন।

**Core Idea:**
আমরা `haystack`-এর উপর দিয়ে একটি "উইন্ডো" স্লাইড করব, যার দৈর্ঘ্য `needle`-এর দৈর্ঘ্যের সমান। `haystack`-এর প্রতিটি পজিশন থেকে, আমরা দেখব যে পরবর্তী `needle.length()` সংখ্যক অক্ষর `needle`-এর সাথে মেলে কি না।

**Algorithm:**
1.  **Edge Cases:**
    *   যদি `needle` খালি হয়, `0` রিটার্ন করো।
    *   যদি `needle`-এর দৈর্ঘ্য `haystack`-এর চেয়ে বেশি হয়, `-1` রিটার্ন করো।
2.  `haystack`-এর উপর দিয়ে একটি `for` লুপ চালাও। লুপটি `i` কে `0` থেকে `haystack.length() - needle.length()` পর্যন্ত চালাবে। `i` হলো `haystack`-এ `needle`-এর সম্ভাব্য শুরুর ইনডেক্স।
3.  ভেতরে, আরেকটি `for` লুপ (`j` দিয়ে) `0` থেকে `needle.length() - 1` পর্যন্ত চালাও।
4.  **Core Logic:** `haystack[i+j]` এবং `needle[j]`-এর অক্ষরগুলো তুলনা করো।
    *   **যদি কোনো অমিল পাওয়া যায় (`haystack[i+j] != needle[j]`):** ভেতরের লুপটি `break` করে দাও এবং `haystack`-এর পরবর্তী শুরুর পজিশন (`i+1`) থেকে চেষ্টা করো।
    *   **যদি ভেতরের লুপটি সম্পূর্ণ হয় (কোনো অমিল ছাড়াই):** তার মানে আমরা একটি সম্পূর্ণ ম্যাচ পেয়েছি। `i` রিটার্ন করো।
5.  যদি বাইরের লুপটি শেষ হওয়ার পরেও কোনো ম্যাচ না পাওয়া যায়, `-1` রিটার্ন করো।

**C++ Code:**
```cpp
int strStr(string haystack, string needle) {
    int h_len = haystack.length();
    int n_len = needle.length();

    if (n_len == 0) return 0;
    if (h_len < n_len) return -1;

    // haystack-এর উপর দিয়ে স্লাইড করি
    for (int i = 0; i <= h_len - n_len; ++i) {
        int j = 0;
        // needle-এর সাথে ম্যাচ করার চেষ্টা করি
        for (; j < n_len; ++j) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        // যদি পুরো needle ম্যাচ করে (j সম্পূর্ণ হয়)
        if (j == n_len) {
            return i;
        }
    }

    return -1;
}
```

**Complexity Analysis:**
*   **Time Complexity: O(m * n)**, যেখানে `m` হলো `haystack`-এর দৈর্ঘ্য এবং `n` হলো `needle`-এর দৈর্ঘ্য। সবচেয়ে খারাপ ক্ষেত্রে (যেমন, `haystack="aaaaaaaaab", needle="aaab"`), প্রতিটি `haystack` পজিশনের জন্য আমাদের `needle`-এর প্রায় পুরোটা চেক করতে হয়।
*   **Space Complexity: O(1):** কোনো অতিরিক্ত স্পেস ব্যবহার করা হয়নি।

**Verdict:** এটি একটি কার্যকর কিন্তু অদক্ষ সমাধান। ছোট স্ট্রিং-এর জন্য এটি ঠিক আছে, কিন্তু বড় স্ট্রিং-এর জন্য এটি ধীর হতে পারে।

#### **Approach-2: Dry Run (`haystack = "sadbutsad", needle = "sad"`)**
1.  **i = 0:**
    *   `j=0`: `haystack[0]` ('s') == `needle[0]` ('s')? Yes.
    *   `j=1`: `haystack[1]` ('a') == `needle[1]` ('a')? Yes.
    *   `j=2`: `haystack[2]` ('d') == `needle[2]` ('d')? Yes.
    *   `j` এখন `3`, যা `n_len`-এর সমান। ভেতরের লুপ শেষ।
    *   **ম্যাচ পাওয়া গেছে! `i = 0` রিটার্ন করো।**
2.  **Final Result:** `0`।

---

### **Approach 3: Knuth-Morris-Pratt (KMP) Algorithm (Advanced)**

এটি একটি লিনিয়ার টাইম (O(m+n)) স্ট্রিং ম্যাচিং অ্যালগরিদম। ইন্টারভিউতে এটি ইমপ্লিমেন্ট করতে বলাটা বিরল (যদি না আপনি খুবই সিনিয়র পদের জন্য ইন্টারভিউ দেন), কিন্তু এর পেছনের ধারণাটি ব্যাখ্যা করতে বলাটা খুবই সাধারণ।

**Core Idea:**
ব্রুট-ফোর্স পদ্ধতিতে, যখন একটি অমিল পাওয়া যায়, আমরা `haystack`-এর পয়েন্টারকে শুধু এক ঘর এগিয়ে নিয়ে আবার `needle`-এর শুরু থেকে মেলানো শুরু করি। এটি অদক্ষ কারণ আমরা `needle`-এর ইতোমধ্যে ম্যাচ হওয়া অংশ থেকে পাওয়া তথ্যকে কাজে লাগাই না।

KMP অ্যালগরিদম `needle`-এর জন্য একটি **LPS (Longest Proper Prefix which is also Suffix)** অ্যারে তৈরি করে। এই অ্যারেটি আমাদের বলে দেয় যে, একটি অমিল পাওয়ার পর `needle`-এর পয়েন্টারকে কত ঘর পিছিয়ে নিতে হবে, যাতে আমরা অপ্রয়োজনীয় তুলনা এড়িয়ে যেতে পারি।

**Algorithm:**
1.  **Preprocessing (LPS Array Creation):**
    *   `needle`-এর জন্য একটি `lps` অ্যারে তৈরি করো। `lps[i]` হবে `needle[0...i]` সাবস্ট্রিং-এর দীর্ঘতম proper prefix যা তার suffix-এরও সমান।
    *   এটি O(n) সময়ে করা যায়।
2.  **Matching:**
    *   দুটি পয়েন্টার, `i` (`haystack`-এর জন্য) এবং `j` (`needle`-এর জন্য) ব্যবহার করে ম্যাচিং শুরু করো।
    *   যদি `haystack[i] == needle[j]` হয়, `i` এবং `j` উভয়কেই বাড়াও।
    *   যদি `haystack[i] != needle[j]` হয়:
        *   যদি `j != 0` হয়, তাহলে `j`-কে `lps[j-1]`-এ সেট করো। `i`-কে অপরিবর্তিত রাখো।
        *   যদি `j == 0` হয়, তাহলে শুধু `i`-কে বাড়াও।
    *   যদি `j` `needle`-এর দৈর্ঘ্যের সমান হয়ে যায়, তার মানে আমরা একটি ম্যাচ পেয়েছি। `i - j` রিটার্ন করো।

**C++ Code (Full KMP):**
```cpp
vector<int> computeLPS(const string& needle) {
    int n = needle.length();
    vector<int> lps(n, 0);
    int length = 0;
    int i = 1;

    while (i < n) {
        if (needle[i] == needle[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int strStr_kmp(string haystack, string needle) {
    int m = haystack.length();
    int n = needle.length();

    if (n == 0) return 0;

    vector<int> lps = computeLPS(needle);
    int i = 0; // index for haystack
    int j = 0; // index for needle

    while (i < m) {
        if (needle[j] == haystack[i]) {
            i++;
            j++;
        }

        if (j == n) {
            return i - j;
        } else if (i < m && needle[j] != haystack[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return -1;
}
```

**Complexity Analysis:**
*   **Time Complexity: O(m + n):** LPS অ্যারে তৈরি করতে O(n) এবং ম্যাচিং করতে O(m) সময় লাগে।
*   **Space Complexity: O(n):** LPS অ্যারের জন্য।

**Verdict:** এটি **সর্বোত্তম সমাধান** এবং স্ট্রিং অ্যালগরিদমের গভীর জ্ঞান প্রদর্শন করে।

---

### **Summary of Approaches**

| Approach  | Time Complexity | Space Complexity | Verdict  |
| :--- | :--- | :--- | :--- |
| **Library Functions** | Varies (usually O(m*n) or O(m+n)) | Varies | ইন্টারভিউয়ের জন্য উপযুক্ত নয়। |
| **Brute Force** | O(m * n) | O(1) | সহজবোধ্য, কিন্তু অদক্ষ। এটি একটি ভালো সূচনা বিন্দু। |
| **KMP Algorithm** | **O(m + n)** | **O(n)** | **সর্বোত্তম সমাধান।** কার্যকর এবং স্ট্রিং অ্যালগরিদমের গভীর জ্ঞান প্রদর্শন করে। |