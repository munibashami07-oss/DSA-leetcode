# Smallest Possible Whole Number

## What was asked

Given two integers `N` and `K`, you may repeatedly perform the operation:
change `N` to `N - K` (i.e. subtract `K` from `N`), any number of times
(including zero).

**Task:** For each test case, find the smallest **non-negative** value of
`N` you can reach this way.

### Input
- First line: `T` — number of test cases.
- Each test case: a single line with two integers `N K`.

### Output
For each test case, print the smallest non-negative value reachable.

### Constraints
- `1 ≤ T ≤ 10^5`
- `1 ≤ N ≤ 10^9`
- `0 ≤ K ≤ 10^9`

### Sample

**Input**
```
3
5 2
4 4
2 5
```

**Output**
```
1
0
2
```

## Approach

Repeatedly subtracting `K` from `N`, stopping just before it would go
negative, drives `N` down to the remainder after removing as many full
copies of `K` as possible — i.e. `N mod K`.

This also naturally handles the case where `K > N` (as in the third sample,
`2 5`): zero operations are performed, and `N mod K` correctly evaluates to
`N` itself (`2 % 5 = 2`).

**Special case — `K = 0`:** subtracting `0` never changes `N`, and the
modulo operation is undefined for a divisor of `0`. In this case the answer
is simply `N` (no operation can help), which is handled separately.

Verification against the sample:
- `5 2` → `5 % 2 = 1` ✓
- `4 4` → `4 % 4 = 0` ✓
- `2 5` → `2 % 5 = 2` ✓ (K bigger than N, zero operations)

Each test case is O(1), so the whole solution runs in O(T), well within
limits even for `T = 10^5`.

## Files
- `solution.cpp` — the C++ solution.

## Build & run

```bash
g++ -O2 -o solution solution.cpp
./solution < input.txt
```