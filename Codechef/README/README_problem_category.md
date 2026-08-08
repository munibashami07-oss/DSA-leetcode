# Problem Category

## What was asked

Chef prepared a problem rated `x` points. Based on `x`, the problem falls
into one of three categories:

1. **Easy** if `1 ≤ x < 100`
2. **Medium** if `100 ≤ x < 200`
3. **Hard** if `200 ≤ x ≤ 300`

**Task:** For each test case, output the category of Chef's problem.

### Input
- First line: `T` — number of test cases.
- Each test case: a single line with the integer `x`.

### Output
For each test case, print `Easy`, `Medium`, or `Hard` (case-sensitive) on
its own line.

### Constraints
- `1 ≤ T ≤ 50`
- `1 ≤ x ≤ 300`

### Sample

**Input**
```
3
50
172
201
```

**Output**
```
Easy
Medium
Hard
```

## Approach

A direct range check per test case:

- If `x < 100` → `Easy`
- Else if `x < 200` → `Medium`
- Else → `Hard` (covers `200 ≤ x ≤ 300`, matching the constraints)

Each check is O(1), so the whole solution runs in O(T).

## Files
- `solution.cpp` — the C++ solution.

## Build & run

```bash
g++ -O2 -o solution solution.cpp
./solution < input.txt
```