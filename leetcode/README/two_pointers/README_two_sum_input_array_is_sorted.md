# Two Sum II - Input Array Is Sorted

## What was asked

Given a **1-indexed** array of integers `numbers` that is already sorted
in **non-decreasing** order, find two numbers such that they add up to a
specific `target`. Return the indices of the two numbers (1-indexed) as
an array `[index1, index2]`, where `index1 < index2`.

The solution must use only **O(1)** extra space, and the problem
guarantees exactly one valid answer, using each element at most once.

*(This is [LeetCode 167 — Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/).)*

### Example
```
Input:  numbers = [2, 7, 11, 15], target = 9
Output: [1, 2]
Explanation: numbers[0] + numbers[1] = 2 + 7 = 9, so index1 = 1, index2 = 2.

Input:  numbers = [2, 3, 4], target = 6
Output: [1, 3]

Input:  numbers = [-1, 0], target = -1
Output: [1, 2]
```

## Approach

Because the array is already sorted, a **two-pointer** sweep from both
ends works directly, with no extra data structure needed:

1. Set `left = 0` (smallest value) and `right = numbers.size() - 1`
   (largest value).
2. Compute `sum = numbers[left] + numbers[right]`.
   - If `sum == target`, the pair is found — return
     `{left + 1, right + 1}` (converted to 1-indexed).
   - If `sum < target`, the sum needs to be larger, so move `left`
     rightward to bring in a bigger value.
   - If `sum > target`, the sum needs to be smaller, so move `right`
     leftward to bring in a smaller value.
3. Repeat until `left` and `right` meet.

Each step moves one pointer inward, so the whole array is scanned at most
once: **O(n)** time and **O(1)** extra space (aside from the small
2-element output array).

## Files
- `two_sum_ii.cpp` — the `Solution` class plus a small test driver with
  `main()` that runs it against the standard LeetCode examples and a
  couple of extra edge cases (duplicate values, answer not at the
  array's edges).

## Build & run

```bash
g++ -O2 -o solution two_sum_ii.cpp
./solution
```

Expected output:
```
Input:    numbers = [2, 7, 11, 15], target = 9
Output:   [1, 2]
Expected: [1, 2]
PASS

Input:    numbers = [2, 3, 4], target = 6
Output:   [1, 3]
Expected: [1, 3]
PASS

Input:    numbers = [-1, 0], target = -1
Output:   [1, 2]
Expected: [1, 2]
PASS

Input:    numbers = [1, 2, 3, 4, 4, 9], target = 8
Output:   [4, 5]
Expected: [4, 5]
PASS

Input:    numbers = [5, 25, 75], target = 100
Output:   [2, 3]
Expected: [2, 3]
PASS
```