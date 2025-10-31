# Leetcode Top 150 Solutions

This repository contains structured solutions to selected Leetcode Top 150 problems. Each problem folder includes multiple approaches in Python, along with step-by-step explanations in markdown format.

## Table of Contents
- [12. Integer to Roman](#12-integer-to-roman)
- [13. Roman to Integer](#13-roman-to-integer)
- [6. Zigzag Conversion](#6-zigzag-conversion)
- [28. Find the index of the First Occurrence in a string](#28-find-the-index-of-the-first-occurrence-in-a-string)
- [26. Remove Duplicate from Sorted Array](#26-remove-dupplicate-from-sorted-array)
- [27. Remove Element](#27-remove-element)
- [42. Trapping Rain Water](#42-trapping-rain-water)
- [80. Remove Duplicates from Sorted Array II](#80-remove-duplicates-from-sorted-array-ii)
- [88. Merge Sorted Array](#88-merge-sorted-array)
- [189. Rotate Array](#189-rotate-array)
- [242. Valid Anagram](#242-valid-anagram)
- [55. Jump Game](#55-jump-game)
- [45. Jump Game II](#45-jump-game-ii)

---

## 242. Valid Anagram
**Folder:** `242 Valid Anagram/`

- **Approch_01_Sorting.py**: Solution using sorting.
- **Approch_02_Hash_map.py**: Solution using hash map.
- **Approch_03_counter_method.py**: Solution using Python's Counter.
- **Solution_step.md**: Step-by-step explanation of all approaches.

## 55. Jump Game
**Folder:** `55 Jump Game/`

- **jump_game.py**: Solution implementation.
- **solution_steps.md**: Step-by-step explanation of the approach.

## 45. Jump Game II
**Folder:** `45 Jump Game II/`

- **DP_jump_game.py**: Dynamic programming approach.
- **Optimal_jump_game.py**: Greedy/optimal approach.
- **solution_steps.md**: Step-by-step explanation and complexity analysis.

---

## 13. Roman to Integer
**Folder:** `13 Roman to Integer/`

- **Approach_01.py**: Left-to-right traversal implementation (handles subtraction cases).
- **Approach_02.py**: Right-to-left traversal / alternative implementation.
- **Problem_link.txt**: Link to the LeetCode problem statement.
- **Solution_steps.md**: Step-by-step explanation, examples, and complexity analysis.

## 6. Zigzag Conversion
**Folder:** `6 Zigzag Conversion/`

- **Approach_01_Simulation_by_raw.cpp**: Simulation of writing in zigzag lines and reading row-by-row (straightforward implementation).
- **solution.md**: Explanation, examples, and complexity analysis (O(n) time, O(n) space for naive row storage).

## 28. Find the index of the First Occurrence in a string
**Folder:** `28 Find the index of the First Occurrence in a string/`

- **Approach_01_STL.cpp**: Use standard library find/search utilities (straightforward, good for prototyping).
- **Approach_02_Sliding_window.cpp**: Rolling/sliding-window or KMP-like approach for better worst-case performance.
- **solution.md**: Explanation, examples, and complexity analysis.

---

## 12. Integer to Roman
**Folder:** `12 Integer to Roman/`

- **Approach_01_Greedy.py**: Greedy value-symbol subtraction approach (recommended).
- **Approach_02_Place_value_method.py**: Place-value/hardcoded arrays per digit.
- **problem_link.txt**: Link to the LeetCode problem statement.
- **solution_steps.md**: Step-by-step explanation, examples, and complexity analysis.

---

## 189. Rotate Array
**Folder:** `189 Rotate Array/`

- **Approach_01_Brute_force.py**: Rotate by popping/inserting (O(N*k)).
- **Approach_02_Using_extra_array.py**: Use auxiliary array then copy (O(N) time, O(N) space).
- **Approach_03_reversal_Algorithm.py**: In-place reversal algorithm (O(N) time, O(1) space) — recommended.
- **problem_link.txt**: Link to the LeetCode problem statement.
- **solution_steps.md**: Explanation, code, and complexity analysis for three approaches.

---

## 26. Remove Dupplicate from Sorted Array
**Folder:** `26 Remove Dupplicate from Sorted Array/`

- **Approach_01_Brute_force.cpp**: Brute force approach.
- **Approach_02_Two_pointer.cpp**: Two-pointer in-place solution (recommended).
- **solution_steps.md**: Explanation and complexity analysis.

## 27. Remove Element
**Folder:** `27 Remove Element/`

- **Approach_02_Two_pointer.py**: Two-pointer in-place removal solution.
- **Approch_01_Slow_and_Fast.py**: Another two-pointer variant.
- **solution_steps.md**: Explanation and edge-cases.

## 42. Trapping Rain Water
**Folder:** `42 Trapping Rain Water/`

- **Approach_1_Brute_Force.cpp**: Brute force scanning approach (O(n^2) time).
- **Approach_2_Dynamic_Programming.cpp**: Precompute left/right max arrays (O(n) time, O(n) space).
- **Approach_3_Two_Pointers.cpp**: Two-pointer optimized method (O(n) time, O(1) space) — recommended.
- **solution.md**: Explanation, examples, and complexity analysis.

## 80. Remove Duplicates from Sorted Array II
**Folder:** `80 Remove Duplicates from Sorted Array II/`

- **Approach_01_Using_Extra_array.cpp**: Extra-array based method.
- **Approach_02_Two_Pointer.cpp**: Two-pointer in-place method.
- **solution_steps.md**: Explanation and comparisons.

## 88. Merge Sorted Array
**Folder:** `88 Merge Sorted Array/`

- **Approach_01_Merge_And_Sort.py**: Simple merge-then-sort approach.
- **Approach_02_Two_pointer_from_The_end.py**: Two-pointer from end in-place merge (recommended).
- **solution_steps.md**: Explanation and complexity notes.

## Usage
1. Browse to the folder of the desired problem.
2. Review the Python files for different solution approaches.
3. Refer to the markdown files for detailed explanations.

## Contribution
Feel free to add new problems or approaches by following the existing folder and file structure.

## License
This repository is for educational purposes.
