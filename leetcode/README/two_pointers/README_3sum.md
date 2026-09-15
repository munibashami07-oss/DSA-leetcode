# 3Sum

## What was asked

Given an integer array `nums`, return all the triplets
`[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, `j != k`, and
`nums[i] + nums[j] + nums[k] == 0`.

The solution set must not contain duplicate triplets.

*(This is [LeetCode 15 — 3Sum](https://leetcode.com/problems/3sum/).)*

### Example
```
Input:  nums = [-1, 0, 1, 2, -1, -4]
Output: [[-1, -1, 2], [-1, 0, 1]]

Input:  nums = [0, 1, 1]
Output: []

Input:  nums = [0, 0, 0]
Output: [[0, 0, 0]]
```

## Approach

This reduces the problem to repeated applications of the two-pointer
"Two Sum on a sorted array" technique:

1. **Sort** `nums`. Sorting makes it possible to both use two pointers
   and to easily skip duplicate values.
2. **Fix the first number** with an outer loop over index `i` (the
   smallest of the three in the triplet, since the array is sorted).
   Skip `i` if it repeats the previous value, so the same first number
   isn't used to generate duplicate triplets.
3. For the fixed `nums[i]`, find pairs from the rest of the array (from
   `i + 1` to the end) that sum to `-nums[i]`, using the standard
   two-pointer sweep:
   - `left` starts right after `i`, `right` starts at the end.
   - If `nums[i] + nums[left] + nums[right] == 0`, record the triplet,
     then move both pointers inward — skipping over any repeated values
     at the new `left`/`right` positions so the same pair isn't recorded
     twice.
   - If the sum is negative, `left++` (need a bigger value).
   - If the sum is positive, `right--` (need a smaller value).

Sorting costs O(n log n), and the outer loop combined with the inner
two-pointer sweep costs O(n) per fixed `i`, so the total is **O(n²)**
time. Extra space is O(1) beyond the output (aside from the space used
by `sort`).

## Files
- `three_sum.cpp` — the `Solution` class plus a small test driver with
  `main()` that runs it against the standard LeetCode examples and a
  couple of extra edge cases (empty array, all-zero array with many
  duplicates).

## Build & run

```bash
g++ -O2 -o solution three_sum.cpp
./solution
```

Expected output:
```
Input:    [-1, 0, 1, 2, -1, -4]
Output:   [[-1, -1, 2], [-1, 0, 1]]
Expected: [[-1, -1, 2], [-1, 0, 1]]
PASS

Input:    [0, 1, 1]
Output:   []
Expected: []
PASS

Input:    [0, 0, 0]
Output:   [[0, 0, 0]]
Expected: [[0, 0, 0]]
PASS

Input:    []
Output:   []
Expected: []
PASS

Input:    [0, 0, 0, 0]
Output:   [[0, 0, 0]]
Expected: [[0, 0, 0]]
PASS
```