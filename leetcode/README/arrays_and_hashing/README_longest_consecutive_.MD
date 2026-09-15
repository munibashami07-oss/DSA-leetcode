# Longest Consecutive Sequence

## What was asked

Given an unsorted array of integers `nums`, return the length of the
longest consecutive elements sequence (a run of consecutive integers, not
necessarily contiguous in the array or in sorted order in the input).

The algorithm must run in **O(n)** time.

*(This is [LeetCode 128 — Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/).)*

### Example
```
Input:  nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive sequence is [1, 2, 3, 4].

Input:  nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output: 9
Explanation: The longest consecutive sequence is [0, 1, 2, ..., 8].
```

## Approach

A naive approach (sort, then scan for runs) works but costs O(n log n).
To hit O(n), the key idea is to use a **hash set** for O(1) average-time
membership checks, and to only ever start counting a sequence from its
smallest element — so no number is ever the starting point of more than
one scan:

1. Insert all numbers into an `unordered_set` (this also removes
   duplicates for free).
2. For each number `num` in the set, check whether `num - 1` is **not**
   in the set. If it isn't, `num` must be the start of a sequence (there's
   nothing smaller connected to it).
3. From that starting point, keep checking `num + 1`, `num + 2`, ... as
   long as each is present in the set, counting the length of the run.
4. Track the maximum run length seen.

Because every element is only ever the *start* of a scan once (elements
that have a predecessor in the set are skipped as starting points), each
element is visited a bounded number of times overall, giving amortized
O(n) time despite the nested loop.

## Files
- `longest_consecutive.cpp` — the `Solution` class plus a small test
  driver with `main()` that runs it against the standard LeetCode
  examples and a few edge cases (empty array, single element,
  duplicates).

## Build & run

```bash
g++ -O2 -o solution longest_consecutive.cpp
./solution
```

Expected output:
```
Input:    [100, 4, 200, 1, 3, 2]
Output:   4
Expected: 4
PASS

Input:    [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]
Output:   9
Expected: 9
PASS

Input:    []
Output:   0
Expected: 0
PASS

Input:    [5]
Output:   1
Expected: 1
PASS

Input:    [1, 2, 0, 1]
Output:   3
Expected: 3
PASS
```