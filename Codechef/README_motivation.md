# Motivation (Best Movie to Watch)

## What was asked

Chef has `X` GB of free hard disk space and wants to watch one motivational
movie during exam time. His friend has `N` movies, each described by a pair
`(Si, Ri)` — the space the movie requires and its IMDB rating.

**Task:** Among all movies that fit in the remaining space (`Si ≤ X`), find
the highest IMDB rating `Ri`. It's guaranteed at least one movie fits.

### Input
- First line: `T` — number of test cases.
- For each test case:
  - A line with `N` and `X`.
  - `N` lines follow, each with `Si` and `Ri` for one movie.

### Output
For each test case, print the highest rating among movies that fit within
`X` GB.

### Constraints
- `1 ≤ T ≤ 10`
- `1 ≤ N ≤ 5·10^4`
- `1 ≤ X ≤ 10^9`
- `1 ≤ Si, Ri ≤ 10^9`
- At least one movie satisfies `Si ≤ X`

### Sample

**Input**
```
3
1 1
1 1
2 2
1 50
2 100
3 2
1 51
3 100
2 50
```

**Output**
```
1
100
51
```

## Approach

This is a straightforward filter-and-max problem — no special algorithm or
data structure is needed:

1. For each movie `(Si, Ri)` in a test case, check if it fits: `Si ≤ X`.
2. Among all movies that fit, keep track of the maximum `Ri` seen so far.
3. Print that maximum once all `N` movies have been processed.

Each test case is processed in O(N) time by scanning the movies once and
maintaining a running maximum, giving O(N) per test case and O(sum of N)
overall — well within the limits.

## Files
- `solution.cpp` — the C++ solution.

## Build & run

```bash
g++ -O2 -o solution solution.cpp
./solution < input.txt
```