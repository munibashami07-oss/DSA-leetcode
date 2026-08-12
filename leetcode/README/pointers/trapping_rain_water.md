# Trapping Rain Water

A C++ solution to the classic "Trapping Rain Water" problem, solved using the two-pointer technique in O(n) time and O(1) space.

## Problem Statement

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

### Example

```
Input:  height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
```

Visually:

```
       #
   #   ##  #
 # ##  #####
0102103213421   <- this row isn't the array, just illustrating shape
```

Water sits on top of a bar wherever there's a taller bar to its left *and* a taller (or equal) bar to its right. The amount of water above any bar equals `min(leftMax, rightMax) - height[i]`, where `leftMax` and `rightMax` are the tallest bars seen so far to the left and right of that position.

## Approach: Two Pointers

1. Start with `left = 0` and `right = n - 1`, along with running maximums `leftMax = 0` and `rightMax = 0`.
2. Compare `height[left]` and `height[right]`:
   - If `height[left] < height[right]`, the water level at `left` is bounded by `leftMax` (we know something at least as tall as `height[left]` exists further right, so `rightMax` isn't the constraint here). Update `leftMax`, add `leftMax - height[left]` to the total, and move `left` forward.
   - Otherwise, do the symmetric operation on the `right` side using `rightMax`.
3. Continue until `left` and `right` meet.

### Why This Works

At any point, whichever side has the smaller current bar is the side whose water level we can safely compute — because the taller running max on the *other* side guarantees the water is capped by the current side's own running max, not the far side's. This avoids the need to precompute left-max and right-max arrays (which would take O(n) extra space), collapsing the classic O(n) space solution down to O(1) extra space while keeping O(n) time.

## Complexity

| Metric | Complexity |
|--------|-----------|
| Time   | O(n) — each pointer moves at most n times total |
| Space  | O(1) — only a few extra variables used |

This improves on the brute-force approach (O(n²), checking left/right max for every bar) and the precomputed-arrays approach (O(n) time but O(n) extra space).

## Files

- `main.cpp` — Contains the `Solution` class with the `trap` method, plus a `main()` function with test cases.

## Building and Running

Compile with any C++11 (or later) compliant compiler:

```bash
g++ -std=c++17 -O2 -o main main.cpp
./main
```

### Expected Output

```
Test 1: 6 (expected 6)
Test 2: 9 (expected 9)
Test 3: 0 (expected 0)
Test 4: 0 (expected 0)
```

## Test Cases

| Input | Expected Output |
|-------|-----------------|
| `[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]` | 6 |
| `[4, 2, 0, 3, 2, 5]` | 9 |
| `[1, 1, 1, 1]` | 0 (flat surface, nothing to trap) |
| `[]` | 0 (empty input) |