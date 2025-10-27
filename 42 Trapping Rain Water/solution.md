### **Problem Statement**

তোমাকে `n`টি নন-নেগেটিভ ইন্টিজারের একটি অ্যারে `height` দেওয়া হবে, যা একটি এলিভেশন ম্যাপ (elevation map) বা উচ্চতার মানচিত্র নির্দেশ করে। প্রতিটি বারের প্রস্থ (width) `1`।

তোমার কাজ হলো বৃষ্টি হওয়ার পর এই মানচিত্রে মোট কত ইউনিট পানি জমতে পারবে, তা গণনা করা।

**Example:**
*   `height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]`
*   **Result:** `6`
*   **(ছবি দেখে কল্পনা করলে বিষয়টি পরিষ্কার হবে)**

### **Core Idea & Challenge**

এই সমস্যার মূল ভিত্তি হলো একটি সহজ প্রশ্ন: **যেকোনো একটি নির্দিষ্ট পজিশন `i`-তে কতটুকু পানি জমতে পারে?**

পানি জমতে পারে দুটি দেয়ালের মাঝখানে। `i`-তম পজিশনে পানির উচ্চতা নির্ধারিত হবে তার **বাম দিকের সর্বোচ্চ দেয়াল** এবং **ডান দিকের সর্বোচ্চ দেয়ালের** মধ্যে যেটি **ছোট**, সেই দেয়ালের উচ্চতা দ্বারা।

সুতরাং, `i`-তম পজিশনে জমা পানির পরিমাণ হলো:
`water_at_i = min(max_height_to_the_left, max_height_to_the_right) - height[i]`

তবে, যদি `height[i]` নিজেই দেয়ালের অংশ হয়, তবে সেখানে পানি জমবে না। তাই, সূত্রটি হবে:
`water_at_i = max(0, min(max_left, max_right) - height[i])`

মোট জমা পানি হবে সব `i`-এর জন্য `water_at_i`-এর যোগফল। মূল চ্যালেঞ্জ হলো `max_left` এবং `max_right` কার্যকরভাবে খুঁজে বের করা।

---

### **Approach 1: Brute Force**

এটি সবচেয়ে সহজবোধ্য পদ্ধতি, যেখানে আমরা সরাসরি মূল ধারণাটি ইমপ্লিমেন্ট করি।

**Algorithm:**
1.  একটি `total_water` ভেরিয়েবল `0` দিয়ে শুরু করো।
2.  অ্যারের প্রতিটি পজিশন `i`-এর জন্য (প্রথম এবং শেষ বার বাদে) একটি লুপ চালাও।
3.  প্রতিটি `i`-এর জন্য:
    *   তার বাম দিকে (`0` থেকে `i` পর্যন্ত) সর্বোচ্চ উচ্চতা `max_left` খুঁজে বের করো।
    *   তার ডান দিকে (`i` থেকে `n-1` পর্যন্ত) সর্বোচ্চ উচ্চতা `max_right` খুঁজে বের করো।
    *   `water_at_i = min(max_left, max_right) - height[i]` গণনা করো।
    *   যদি `water_at_i > 0` হয়, তবে `total_water`-এর সাথে যোগ করো।
4.  `total_water` রিটার্ন করো।

**C++ Code:**
```cpp
int trap_brute_force(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;

    int total_water = 0;
    for (int i = 1; i < n - 1; ++i) {
        int max_left = 0;
        for (int j = i; j >= 0; --j) {
            max_left = max(max_left, height[j]);
        }

        int max_right = 0;
        for (int j = i; j < n; ++j) {
            max_right = max(max_right, height[j]);
        }
        
        int water_at_i = min(max_left, max_right) - height[i];
        if (water_at_i > 0) {
            total_water += water_at_i;
        }
    }
    return total_water;
}
```

**Complexity Analysis:**
*   **Time Complexity: O(N²):** বাইরের লুপটি O(N) বার চলে, এবং প্রতিটি ইটারেশনে `max_left` ও `max_right` বের করতে দুটি অভ্যন্তরীণ লুপ O(N) সময় নেয়।
*   **Space Complexity: O(1):** কোনো অতিরিক্ত স্পেস ব্যবহার করা হয়নি।

**Verdict:** খুবই অদক্ষ এবং বড় ইনপুটের জন্য LeetCode-এ "Time Limit Exceeded" (TLE) দেবে।

---

### **Approach 2: Dynamic Programming (Using Pre-computed Arrays)**

ব্রুট-ফোর্স পদ্ধতিতে আমরা বারবার `max_left` এবং `max_right` গণনা করছি। আমরা যদি এই মানগুলো আগে থেকেই গণনা করে রাখতে পারি, তাহলে টাইম কমপ্লেক্সিটি কমে যাবে।

**Algorithm:**
1.  `n` সাইজের একটি `left_max` অ্যারে তৈরি করো। `left_max[i]` হবে `i`-তম পজিশনের বাম দিকে (সহ) সর্বোচ্চ দেয়ালের উচ্চতা। এটি একটি বাম-থেকে-ডানে পাস দিয়ে গণনা করা যায়।
2.  `n` সাইজের একটি `right_max` অ্যারে তৈরি করো। `right_max[i]` হবে `i`-তম পজিশনের ডান দিকে (সহ) সর্বোচ্চ দেয়ালের উচ্চতা। এটি একটি ডান-থেকে-বামে পাস দিয়ে গণনা করা যায়।
3.  এবার, অ্যারের উপর দিয়ে তৃতীয়বার লুপ চালাও। প্রতিটি `i`-এর জন্য `water_at_i = min(left_max[i], right_max[i]) - height[i]` গণনা করে মোট পানির সাথে যোগ করো।

**C++ Code:**
```cpp
int trap_dp(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;

    vector<int> left_max(n);
    vector<int> right_max(n);

    // Pass 1: Fill left_max array
    left_max[0] = height[0];
    for (int i = 1; i < n; ++i) {
        left_max[i] = max(left_max[i - 1], height[i]);
    }

    // Pass 2: Fill right_max array
    right_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        right_max[i] = max(right_max[i + 1], height[i]);
    }

    // Pass 3: Calculate total water
    int total_water = 0;
    for (int i = 0; i < n; ++i) {
        total_water += min(left_max[i], right_max[i]) - height[i];
    }
    return total_water;
}
```

**Complexity Analysis:**
*   **Time Complexity: O(N):** আমরা তিনটি আলাদা পাস ব্যবহার করেছি, যার প্রতিটি O(N) সময় নেয়।
*   **Space Complexity: O(N):** `left_max` এবং `right_max` অ্যারেগুলোর জন্য অতিরিক্ত O(N) স্পেস প্রয়োজন।

**Verdict:** এটি একটি ভালো এবং কার্যকর সমাধান, যা টাইম কমপ্লেক্সিটির দিক থেকে সেরা। কিন্তু এটি অতিরিক্ত স্পেস ব্যবহার করে।

---

### **Approach 3: Two Pointers (Optimal and Best Solution)**

এটিই **সর্বোত্তম সমাধান**, যা লিনিয়ার টাইমে এবং কনস্ট্যান্ট স্পেসে কাজ করে।

**Core Idea:**
DP পদ্ধতিতে আমাদের `left_max` এবং `right_max` উভয়ই আগে থেকে জানার প্রয়োজন ছিল। কিন্তু টু-পয়েন্টার পদ্ধতিতে, আমরা দুটি পয়েন্টার (`left` এবং `right`) অ্যারের দুই প্রান্ত থেকে শুরু করব এবং ভেতরের দিকে এগোব।

মূল যুক্তিটি হলো: যেকোনো একটি পজিশনে জমা পানির পরিমাণ তার **ছোট দেয়ালটি** দ্বারা নির্ধারিত হয়।
*   যদি `left_max < right_max` হয়, তাহলে আমরা নিশ্চিতভাবে বলতে পারি যে `left` পজিশনে জমা পানি `left_max` দ্বারা নির্ধারিত হবে। কারণ, ডানদিকে `right_max` নামে একটি বড় দেয়াল আছে, তাই ডানদিকের প্রকৃত সর্বোচ্চ দেয়ালটি `left_max`-এর চেয়ে বড় বা সমান হবেই।
*   একইভাবে, যদি `right_max <= left_max` হয়, তাহলে `right` পজিশনে জমা পানি `right_max` দ্বারা নির্ধারিত হবে।

**Algorithm:**
1.  `left = 0` এবং `right = n-1` দুটি পয়েন্টার নাও।
2.  `left_max = 0` এবং `right_max = 0` দুটি ভেরিয়েবল নাও।
3.  `total_water = 0` দিয়ে শুরু করো।
4.  যতক্ষণ `left < right` থাকে, ততক্ষণ লুপ চালাও।
5.  যদি `height[left] <= height[right]` হয়:
    *   এর মানে বাম দিকের দেয়ালটি (সম্ভাব্য) ছোট।
    *   `left_max`-কে আপডেট করো: `left_max = max(left_max, height[left])`।
    *   পানি যোগ করো: `total_water += left_max - height[left]`।
    *   `left`-কে এক ঘর ডানে সরাও।
6.  নাহলে (`height[left] > height[right]`):
    *   এর মানে ডান দিকের দেয়ালটি ছোট।
    *   `right_max`-কে আপডেট করো: `right_max = max(right_max, height[right])`।
    *   পানি যোগ করো: `total_water += right_max - height[right]`।
    *   `right`-কে এক ঘর বামে সরাও।
7.  `total_water` রিটার্ন করো।

**C++ Code:**
```cpp
int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;

    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int total_water = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                total_water += left_max - height[left];
            }
            left++;
        } else {
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                total_water += right_max - height[right];
            }
            right--;
        }
    }
    return total_water;
}
```

**Complexity Analysis:**
*   **Time Complexity: O(N):** `left` এবং `right` পয়েন্টার দুটি অ্যারেটি একবারই অতিক্রম করে।
*   **Space Complexity: O(1):** কোনো অতিরিক্ত স্পেস ব্যবহার করা হয়নি।

#### **Approach-3: Dry Run (`height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]`)**

| `left` | `right` | `h[l]` | `h[r]` | `l_max` | `r_max` | `h[l]<=h[r]`? | Action | `water` |
|---|---|---|---|---|---|---|---|---|
| 0 | 11 | 0 | 1 | 0 | 0 | True | `l_max=max(0,0)=0`. `water+=0-0=0`. `l++` | 0 |
| 1 | 11 | 1 | 1 | 0 | 0 | True | `l_max=max(0,1)=1`. `water+=1-1=0`. `l++` | 0 |
| 2 | 11 | 0 | 1 | 1 | 0 | True | `l_max=1`. `water+=1-0=1`. `l++` | 1 |
| 3 | 11 | 2 | 1 | 1 | 0 | False | `r_max=max(0,1)=1`. `water+=1-1=0`. `r--` | 1 |
| 3 | 10 | 2 | 2 | 1 | 1 | True | `l_max=max(1,2)=2`. `water+=2-2=0`. `l++` | 1 |
| 4 | 10 | 1 | 2 | 2 | 1 | True | `l_max=2`. `water+=2-1=1`. `l++` | 2 |
| 5 | 10 | 0 | 2 | 2 | 1 | True | `l_max=2`. `water+=2-0=2`. `l++` | 4 |
| 6 | 10 | 1 | 2 | 2 | 1 | True | `l_max=2`. `water+=2-1=1`. `l++` | 5 |
| 7 | 10 | 3 | 2 | 2 | 1 | False | `r_max=max(1,2)=2`. `water+=2-2=0`. `r--` | 5 |
| 7 | 9 | 3 | 1 | 2 | 2 | False | `r_max=2`. `water+=2-1=1`. `r--` | 6 |
| 7 | 8 | 3 | 2 | 2 | 2 | False | `r_max=2`. `water+=2-2=0`. `r--` | 6 |
| 7 | 7 | - | - | - | - | `l<r` False | **Loop Ends** | 6 |

**Final Result:** `total_water = 6`।

---

### **Summary of Approaches**

| Approach  | Time Complexity | Space Complexity | Verdict  |
| :--- | :--- | :--- | :--- |
| **Brute Force** | O(N²) | O(1) | সহজবোধ্য কিন্তু অদক্ষ। TLE দেবে। |
| **DP / Pre-computation** | O(N) | O(N) | কার্যকর এবং একটি ভালো সমাধান, কিন্তু অতিরিক্ত স্পেস ব্যবহার করে। |
| **Two Pointers** | **O(N)** | **O(1)** | **সর্বোত্তম সমাধান।** কার্যকর, দ্রুত এবং স্পেস-এফিসিয়েন্ট। ইন্টারভিউয়ের জন্য সেরা। |