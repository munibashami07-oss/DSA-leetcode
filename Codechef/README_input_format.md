# Programming Languages

## What was asked

Chef needs a language with two specific features `A` and `B`. He has two
options to switch to:

- A language with features `A1` and `B1`
- A language with features `A2` and `B2`

All four of `A1, B1, A2, B2` are pairwise distinct (from each other), and
`A, B` are distinct from each other too.

**Task:** For each test case, determine whether Chef should switch to the
first language, the second language, or neither.

### Input
- First line: `T` — number of test cases.
- Each test case: a single line with six integers `A B A1 B1 A2 B2`.

### Output
For each test case, print:
- `1` if the first language has exactly the required features `{A, B}`
- `2` if the second language has exactly the required features `{A, B}`
- `0` if neither language matches

### Constraints
- `1 ≤ T ≤ 288`
- `1 ≤ A, B, A1, B1, A2, B2 ≤ 4`
- `A, B` are distinct
- `A1, B1, A2, B2` are pairwise distinct

### Sample

**Input**
```
3
1 2 2 1 3 4
3 4 2 1 4 3
1 2 1 3 2 4
```

**Output**
```
1
2
0
```

## Approach

A language matches Chef's requirement if its feature **set** equals
`{A, B}` — the order the features are listed in doesn't matter (e.g.
`{2, 1}` matches a requirement of `{1, 2}`, as seen in the first sample
case).

So for each test case:
1. Sort the pair `(A, B)` and each candidate pair `(A1, B1)` and
   `(A2, B2)`.
2. Compare the sorted requirement against each sorted candidate.
3. Output `1` if it matches the first language, `2` if it matches the
   second, otherwise `0` (it's guaranteed at most one can match, since
   `A1, B1, A2, B2` are pairwise distinct).

Each test case is checked in O(1), so the whole solution runs in O(T).

## Files
- `solution.cpp` — the C++ solution.

## Build & run

```bash
g++ -O2 -o solution solution.cpp
./solution < input.txt
```