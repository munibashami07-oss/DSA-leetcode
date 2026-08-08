# The Two Dishes

## What was asked

Chef prepared two dishes with integer tastiness values `T1` and `T2`, each
between `0` and `N` (inclusive). Chef forgot the individual values but
remembers their sum `S` (i.e. `T1 + T2 = S`). It's guaranteed at least one
valid pair `{T1, T2}` exists satisfying `T1 + T2 = S` and `0 ≤ T1, T2 ≤ N`.

**Task:** For each test case, find the maximum possible absolute difference
`|T1 - T2|`.

### Input
- First line: `T` — number of test cases.
- Each of the next `T` lines: two space-separated integers `N` and `S`.

### Output
For each test case, print the maximum possible `|T1 - T2|` on its own line.

### Constraints
- `1 ≤ T ≤ 10^3`
- `1 ≤ N ≤ 10^5`
- `1 ≤ S ≤ 2·10^5`

### Sample

**Input**
```
3
3 1
4 4
2 3
```

**Output**
```
1
4
1
```

## Approach

To maximize `|T1 - T2|` given `T1 + T2 = S` and `0 ≤ T1, T2 ≤ N`, push one
dish's value to an extreme (as large or as small as allowed) and let the
other absorb the rest of the sum.

- The **largest** a single dish's tastiness can be is `min(N, S)`
  — it can't exceed `N`, and it can't exceed `S` either (otherwise the
  other dish would need negative tastiness).
- The **smallest** a single dish's tastiness can be is `max(0, S - N)`
  — it can't be negative, and since the other dish can take at most `N`,
  this one must be at least `S - N`.

The maximum difference is then:

```
answer = min(N, S) - max(0, S - N)
```

This runs in O(1) per test case, so the whole solution is O(T).

## Files
- `solution.cpp` — the C++ solution.

## Build & run

```bash
g++ -O2 -o solution solution.cpp
./solution < input.txt
```
