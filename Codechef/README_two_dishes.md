# Two Dishes (Guests)

## What was asked

Chef has `N` guests and must serve at least one dish to each of them (i.e.
prepare at least `N` dishes total). He can make two types of dishes:

- **Type 1**: 1 fruit + 1 vegetable
- **Type 2**: 1 vegetable + 1 fish

Chef has `A` fruits, `B` vegetables, and `C` fishes.

**Task:** Determine whether Chef can prepare at least `N` dishes in total.

### Input
- First line: `T` — number of test cases.
- Each test case: a single line with four integers `N A B C`.

### Output
For each test case, print `YES` if Chef can prepare at least `N` dishes,
otherwise print `NO`.

### Constraints
- `1 ≤ T ≤ 100`
- `1 ≤ N, A, B, C ≤ 100`

### Sample

**Input**
```
4
2 1 2 1
3 2 2 2
4 2 6 3
3 1 3 1
```

**Output**
```
YES
NO
YES
NO
```

## Approach

Let `x` = number of Type 1 dishes made and `y` = number of Type 2 dishes
made. The constraints are:

- `x ≤ A` (limited by fruits)
- `y ≤ C` (limited by fishes)
- `x + y ≤ B` (limited by vegetables, since both types use one each)

We want to maximize the total dishes `x + y`. Since fruits and fishes are
independent resources that each only feed into the vegetable-limited total,
the best Chef can do is use as many fruits and fishes as available, capped
by the vegetable supply:

```
maxDishes = min(A + C, B)
```

Chef can serve all `N` guests if and only if `maxDishes ≥ N`.

This is an O(1) check per test case, so the whole solution runs in O(T).

## Files
- `solution.cpp` — the C++ solution.

## Build & run

```bash
g++ -O2 -o solution solution.cpp
./solution < input.txt
```