# Weight Balance

## What was asked

Chef weighed `w1` kg before lockdown (accurate hospital measurement) and,
after `M` months, his home scale (possibly inaccurate) showed `w2` kg
(`w2 > w1`).

Scientific research says a growing kid's weight increases by somewhere
between `x1` and `x2` kg (inclusive) each month — not necessarily the same
amount every month. Assuming Chef is a growing kid, determine whether the
home scale's reading could be correct.

**Task:** For each test case, output `1` if the reported weight gain is
achievable, or `0` if it isn't.

### Input
- First line: `T` — number of test cases.
- Each test case: a single line with five integers `w1 w2 x1 x2 M`.

### Output
For each test case, print `1` if the scale's result can be correct, or `0`
otherwise.

### Constraints
- `1 ≤ T ≤ 10^5`
- `1 ≤ w1 < w2 ≤ 100`
- `0 ≤ x1 ≤ x2 ≤ 10`
- `1 ≤ M ≤ 10`

### Sample

**Input**
```
5
1 2 1 2 2
2 4 1 2 2
4 8 1 2 2
5 8 1 2 2
1 100 1 2 2
```

**Output**
```
0
1
1
1
0
```

## Approach

The total weight gain reported by the scale is `w2 - w1`. Over `M` months,
if each month's gain is independently chosen from `[x1, x2]`, the smallest
possible total gain is `M * x1` (every month at the minimum) and the
largest possible total gain is `M * x2` (every month at the maximum) —
and every value in between is achievable by mixing months at different
gain levels.

So the scale's reading is plausible exactly when:

```
M * x1 <= (w2 - w1) <= M * x2
```

Verification against the sample (all with `x1=1, x2=2, M=2`, so the valid
gain range is `[2, 4]`):
- `1 2` → gain `1`, outside `[2,4]` → `0` ✓
- `2 4` → gain `2`, inside → `1` ✓
- `4 8` → gain `4`, inside → `1` ✓
- `5 8` → gain `3`, inside → `1` ✓
- `1 100` → gain `99`, outside → `0` ✓

Each test case is O(1), so the whole solution runs in O(T), comfortably
fast even for `T = 10^5`.

## Files
- `solution.cpp` — the C++ solution.

## Build & run

```bash
g++ -O2 -o solution solution.cpp
./solution < input.txt
```