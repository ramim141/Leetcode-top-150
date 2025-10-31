### **Problem Statement**

তোমাকে একটি স্ট্রিং `s` এবং একটি ইন্টিজার `numRows` দেওয়া হবে। তোমাকে স্ট্রিংটিকে একটি জিগজ্যাগ (zigzag) প্যাটার্নে `numRows` সংখ্যক সারিতে লিখতে হবে এবং তারপর সারি-বাই-সারি (row-by-row) পড়ে একটি নতুন স্ট্রিং তৈরি করতে হবে।

**উদাহরণ:**
*   `s = "PAYPALISHIRING"`, `numRows = 3`

জিগজ্যাগ প্যাটার্নটি হবে:
```
P   A   H   N
A P L S I I G
Y   I   R
```
এবার সারি-বাই-সারি পড়লে আমরা পাই: `"PAHNAPLSIIGYIR"`। এটিই হবে আমাদের ফলাফল।

*   `s = "PAYPALISHIRING"`, `numRows = 4`

প্যাটার্নটি হবে:
```
P     I    N
A   L S  I G
Y A   H R
P     I
```
ফলাফল: `"PINALSIGYAHRPI"`

### **Core Challenges & Idea (মূল চ্যালেঞ্জ এবং ধারণা)**

1.  **Pattern Recognition:** এই সমস্যার মূল চ্যালেঞ্জ হলো জিগজ্যাগ প্যাটার্নের মুভমেন্টকে (প্রথমে নিচে, তারপর উপরে-ডানে) কোডে রূপান্তর করা।
2.  **Data Storage:** আমাদের প্রতিটি সারির জন্য অক্ষরগুলো আলাদাভাবে সংরক্ষণ করতে হবে এবং শেষে সেগুলোকে একত্রিত করতে হবে। এর জন্য একটি স্ট্রিং-এর অ্যারে বা ভেক্টর (`vector<string>`) একটি আদর্শ ডেটা স্ট্রাকচার।
3.  **Edge Cases:**
    *   `numRows = 1`: এক্ষেত্রে কোনো জিগজ্যাগ হবে না, স্ট্রিংটি অপরিবর্তিত থাকবে।
    *   `numRows >= s.length()`: এক্ষেত্রেও স্ট্রিংটি অপরিবর্তিত থাকবে কারণ প্রতিটি অক্ষর একটি নতুন সারিতে বসবে।

**Core Idea:** আমরা মূল স্ট্রিং `s`-এর উপর দিয়ে একবার মাত্র ট্র্যাভার্স করব। প্রতিটি অক্ষরের জন্য, আমরা নির্ধারণ করব এটি কোন সারিতে যাবে। আমরা একটি `current_row` ভেরিয়েবল এবং একটি `direction` ভেরিয়েবল ব্যবহার করে এই জিগজ্যাগ মুভমেন্টকে সিমুলেট করতে পারি।

---

### **Approach 1: Simulation by Row (Optimal and Best Solution)**

এটিই সেরা এবং ইন্টারভিউয়ের জন্য উপযুক্ত সমাধান। এটি সরাসরি জিগজ্যাগ প্যাটার্ন তৈরির প্রক্রিয়াকে অনুকরণ করে।

**Algorithm:**
1.  **Edge Case:** যদি `numRows == 1` হয়, তাহলে কোনো পরিবর্তন হবে না, সরাসরি `s` রিটার্ন করো।
2.  **Initialization:**
    *   `numRows` সংখ্যক খালি স্ট্রিং সহ একটি ভেক্টর `rows` তৈরি করো।
    *   `current_row = 0` দিয়ে শুরু করো।
    *   `going_down = false` দিয়ে একটি বুলিয়ান ফ্ল্যাগ শুরু করো (এটি দিক পরিবর্তন ট্র্যাক করবে)।
3.  **Iteration:** `s`-এর প্রতিটি অক্ষর `c`-এর জন্য একটি লুপ চালাও।
4.  **Core Logic:**
    *   `rows[current_row]`-তে অক্ষর `c` যোগ করো।
    *   **Direction Change:** যদি `current_row` প্রথম সারি (`0`) বা শেষ সারিতে (`numRows - 1`) থাকে, তাহলে আমাদের দিক পরিবর্তন করতে হবে। `going_down` ফ্ল্যাগটিকে উল্টে দাও (`going_down = !going_down`)।
    *   **Move to Next Row:**
        *   যদি `going_down` `true` হয়, `current_row`-কে `1` বাড়াও।
        *   নাহলে, `current_row`-কে `1` কমাও।
5.  **Concatenation:** লুপ শেষে, `rows` ভেক্টরের সব স্ট্রিংকে একত্রিত করে চূড়ান্ত ফলাফল তৈরি করো এবং রিটার্ন করো।

**C++ Code:**
```cpp
string convert(string s, int numRows) {
    // Edge Case: যদি numRows 1 হয়, কোনো জিগজ্যাগ হবে না
    if (numRows == 1) {
        return s;
    }

    vector<string> rows(min((int)s.length(), numRows));
    int current_row = 0;
    bool going_down = false;

    for (char c : s) {
        rows[current_row] += c;
        
        // যদি প্রথম বা শেষ সারিতে থাকি, দিক পরিবর্তন করি
        if (current_row == 0 || current_row == numRows - 1) {
            going_down = !going_down;
        }

        // পরবর্তী সারিতে যাই
        current_row += going_down ? 1 : -1;
    }

    // সব সারিকে একত্রিত করি
    string result = "";
    for (const string& row : rows) {
        result += row;
    }

    return result;
}

// Main function for testing
int main() {
    string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    cout << "Input: s = \"" << s1 << "\", numRows = " << numRows1 << endl;
    cout << "Output: " << convert(s1, numRows1) << endl; // Expected: "PAHNAPLSIIGYIR"

    string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    cout << "Input: s = \"" << s2 << "\", numRows = " << numRows2 << endl;
    cout << "Output: " << convert(s2, numRows2) << endl; // Expected: "PINALSIGYAHRPI"

    return 0;
}
```

**Complexity Analysis:**
*   **Time Complexity: O(N):** আমরা মূল স্ট্রিং `s`-এর উপর দিয়ে একবার মাত্র ট্র্যাভার্স করি (`N` হলো `s`-এর দৈর্ঘ্য)। শেষে স্ট্রিংগুলো একত্রিত করতেও O(N) সময় লাগে।
*   **Space Complexity: O(N):** `rows` ভেক্টরে `s`-এর সমস্ত অক্ষর সংরক্ষণ করার জন্য অতিরিক্ত O(N) স্পেস প্রয়োজন।

#### **Approach-1: Dry Run (`s = "PAYPAL", numRows = 3`)**

1.  **Initialization:** `rows = ["", "", ""]`, `current_row = 0`, `going_down = false`

| `char c` | `current_row` (শুরুতে) | Action on `rows` | Boundary Check | `going_down` (শেষে) | `current_row` (শেষে) |
|---|---|---|---|---|---|
| P | 0 | `rows[0] += 'P'` | `0==0` -> True | True | 1 |
| A | 1 | `rows[1] += 'A'` | - | True | 2 |
| Y | 2 | `rows[2] += 'Y'` | `2==2` -> True | False | 1 |
| P | 1 | `rows[1] += 'P'` | - | False | 0 |
| A | 0 | `rows[0] += 'A'` | `0==0` -> True | True | 1 |
| L | 1 | `rows[1] += 'L'` | - | True | 2 |

2.  **লুপ শেষে:**
    *   `rows[0]` = `"PA"`
    *   `rows[1]` = `"APL"`
    *   `rows[2]` = `"Y"`
3.  **Concatenation:** `"PA" + "APL" + "Y"` -> `"PAAPLY"`
4.  **Final Result:** `"PAAPLY"`

---

### **Alternative Approach (Brief Mention): Visiting by Row**

এটি একটি গাণিতিক পদ্ধতি, যা অতিরিক্ত স্পেস ব্যবহার করে না কিন্তু ইমপ্লিমেন্ট করাটা একটু বেশি জটিল।

**Core Idea:**
প্রতিটি সারির জন্য, আমরা গাণিতিকভাবে গণনা করতে পারি যে কোন কোন ইনডেক্সের অক্ষরগুলো সেই সারিতে বসবে।
*   একটি "সাইকেল" এর দৈর্ঘ্য হলো `cycleLen = 2 * numRows - 2`।
*   **সারি 0:** অক্ষরগুলো `0, cycleLen, 2*cycleLen, ...` ইনডেক্সে থাকে।
*   **শেষ সারি:** অক্ষরগুলো `numRows-1, numRows-1 + cycleLen, ...` ইনডেক্সে থাকে।
*   **মাঝের সারি `r`:** অক্ষরগুলো `r + i*cycleLen` (নিচে যাওয়ার পথে) এবং `(i+1)*cycleLen - r` (উপরে যাওয়ার পথে) ইনডেক্সে থাকে।

**Verdict:** যদিও এটি স্পেস-এফিসিয়েন্ট (O(1) অতিরিক্ত স্পেস), সিমুলেশন পদ্ধতিটি বোঝা এবং কোড করা অনেক সহজ এবং সাধারণত ইন্টারভিউতে এটিই আশা করা হয়।

---

### **Summary**

| Approach | Time Complexity | Space Complexity | Verdict  |
| :--- | :--- | :--- | :--- |
| **Simulation by Row** | **O(N)** | **O(N)** | **সর্বোত্তম এবং সহজবোধ্য সমাধান।** এটি সরাসরি সমস্যার ভিজ্যুয়াল প্যাটার্নকে অনুকরণ করে। |
| **Visiting by Row (Math)** | O(N) | O(1) | স্পেস-এফিসিয়েন্ট, কিন্তু কোড করা জটিল এবং ভুল হওয়ার সম্ভাবনা বেশি। |