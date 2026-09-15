# Product of Array Except Self

## What was asked

Given an integer array `nums`, return an array `answer` such that
`answer[i]` is equal to the product of all the elements of `nums` except
`nums[i]`.

The algorithm must run in **O(n)** time, and — as a follow-up constraint —
it must not use the division operator, and it should use only **O(1)**
extra space (not counting the output array).

*(This is [LeetCode 238 — Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/).)*

### Example
```
Input:  nums = [1, 2, 3, 4]
Output: [24, 12, 8, 6]

Input:  nums = [-1, 1, 0, -3, 3]
Output: [0, 0, 9, 0, 0]
```

## Approach

For each index `i`, `answer[i]` is the product of:
- the **prefix product** — everything to the left of `i`, and
- the **suffix product** — everything to the right of `i`.

The trick to doing this in O(1) extra space (besides the output array) is
two passes over the array, reusing the output array itself as scratch
space:

1. **Left-to-right pass:** fill `ans[i]` with the product of all elements
   *before* index `i`. `ans[0] = 1` since there's nothing before it.
2. **Right-to-left pass:** walk backwards while keeping a running
   `suffix` product of everything seen so far. Multiply `ans[i]` by
   `suffix` (this folds in the product of all elements *after* `i`), then
   update `suffix` to include `nums[i]` for the next iteration.

No division is needed, and the only extra variable is the single
`suffix` accumulator, giving O(n) time and O(1) extra space.

## Files
- `solution.cpp` — the `Solution` class plus a small test driver with
  `main()` that runs it against the standard LeetCode examples and a
  couple of edge cases (single element, no zeros).

## Build & run

```bash
g++ -O2 -o solution solution.cpp
./solution
```

Expected output:
```
Input:  [1, 2, 3, 4]
Output: [24, 12, 8, 6]

Input:  [-1, 1, 0, -3, 3]
Output: [0, 0, 9, 0, 0]

Input:  [5]
Output: [1]

Input:  [2, 3]
Output: [3, 2]
```