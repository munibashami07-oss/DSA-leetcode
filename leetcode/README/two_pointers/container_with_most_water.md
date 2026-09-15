# Container With Most Water

A C++ solution to the classic "Container With Most Water" problem, solved using the two-pointer technique.

## Problem Statement

Given an array `height` of non-negative integers, where each element represents the height of a vertical line drawn at that index on the x-axis, find two lines that, together with the x-axis, form a container that holds the maximum amount of water.

**Note:** You may not slant the container — the water level is bounded by the shorter of the two chosen lines.

### Example

```
Input:  height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
Output: 49
```

The container formed by index 1 (height 8) and index 8 (height 7) has:
- width = 8 - 1 = 7
- height = min(8, 7) = 7
- area = 7 × 7 = 49

## Approach: Two Pointers

1. Place one pointer at the start (`left`) and one at the end (`right`) of the array.
2. At each step, compute the area formed by the two lines:
   `area = (right - left) * min(height[left], height[right])`
3. Track the maximum area seen so far.
4. Move the pointer pointing to the **shorter** line inward — moving the taller one can never increase the area (width shrinks and height is still capped by the shorter line), so it's always optimal to move the shorter side.
5. Repeat until the two pointers meet.

### Why This Works

For any pair `(left, right)`, the container's height is limited by the shorter line. If you keep the shorter line fixed and move the taller one inward, the width decreases while the limiting height stays the same (or gets worse) — so the area can only shrink or stay the same. Moving the shorter line, on the other hand, gives a chance to find a taller line that could increase the area. This greedy choice safely eliminates one candidate pair per step without missing the optimal answer.

## Complexity

| Metric | Complexity |
|--------|-----------|
| Time   | O(n) — each pointer moves at most n times total |
| Space  | O(1) — only a few extra variables used |

This is a significant improvement over the brute-force approach of checking all pairs, which runs in O(n²).

## Files

- `main.cpp` — Contains the `Solution` class with the `maxArea` method, plus a `main()` function with test cases.

## Building and Running

Compile with any C++11 (or later) compliant compiler:

```bash
g++ -std=c++17 -O2 -o main main.cpp
./main
```

### Expected Output

```
Test 1: 49 (expected 49)
Test 2: 1 (expected 1)
Test 3: 16 (expected 16)
```

## Test Cases

| Input | Expected Output |
|-------|-----------------|
| `[1, 8, 6, 2, 5, 4, 8, 3, 7]` | 49 |
| `[1, 1]` | 1 |
| `[4, 3, 2, 1, 4]` | 16 |