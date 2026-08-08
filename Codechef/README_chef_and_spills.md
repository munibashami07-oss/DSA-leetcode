# Chef and Spells

## What was asked

Chef has three spells with powers `A`, `B`, and `C`. He starts with `0` hit
points, and using a spell with power `P` adds `P` to his hit points. Chef
must use **exactly two** of the three spells.

**Task:** For each test case, find the maximum number of hit points Chef
can end up with.

### Input
- First line: `T` — number of test cases.
- Each test case: a single line with three integers `A B C`.

### Output
For each test case, print the maximum achievable hit points.

### Constraints
- `1 ≤ T ≤ 10^4`
- `1 ≤ A, B, C ≤ 10^8`

### Sample

**Input**
```
2
4 2 8
10 14 18
```

**Output**
```
12
32
```

## Approach

Since all powers are positive, hit points are maximized by picking the two
**largest** of `A`, `B`, `C` and skipping the smallest one. This is the
same as summing all three and subtracting the minimum:

```
answer = A + B + C - min(A, B, C)
```

Verification against the sample:
- `4 2 8` → total `14`, minus smallest `2` → `12` ✓
- `10 14 18` → total `42`, minus smallest `10` → `32` ✓

Each test case is O(1), so the whole solution runs in O(T). (64-bit
integers are used since the sum can reach `3 × 10^8`, which still fits in
a 32-bit int, but `long long` is used defensively.)

## Files
- `solution.cpp` — the C++ solution.

## Build & run

```bash
g++ -O2 -o solution solution.cpp
./solution < input.txt
```