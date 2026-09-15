# Best Time to Buy and Sell Stock (LeetCode 121)

## Problem Statement

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a **different day in the future** to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return `0`.

**Example 1:**
```
Input:  prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.
```

**Example 2:**
```
Input:  prices = [7,6,4,3,1]
Output: 0
Explanation: Prices only decrease, so no transaction is done and max profit = 0.
```

## Visual Example

```
Prices:  7   1   5   3   6   4
Day:     0   1   2   3   4   5

              min=1
               |
          buy -+          sell
               |            |
               v            v
Prices:  7 [  1   5   3   6 ] 4
Profit if sold on each day (using lowest price so far):
 day1: 1-1=0   day2: 5-1=4   day3: 3-1=2   day4: 6-1=5 <- max   day5: 4-1=3

Answer: 5 (buy at 1, sell at 6)
```

## Algorithm — Plain-Language Explanation

This is a classic **one-pass tracking** problem, closely related in spirit to the two-pointer
technique: instead of checking every possible (buy day, sell day) pair — which would be O(n²) —
we walk through the array **once**, keeping track of two running values:

1. `minPriceSoFar` — the lowest price seen up to (and including) the current day. This is the
   best possible day we *could* have bought on so far.
2. `maxProfit` — the best profit we could make if we sold *today*, given the lowest buy price
   seen so far, kept as a running maximum.

For each day `i` (starting from day 1):
- First, check what profit we'd make if we **sold today** at `prices[i]`, using the cheapest
  price seen so far (`prices[i] - minPriceSoFar`). Update `maxProfit` if this is better.
- Then, update `minPriceSoFar` if today's price is a new low — because a cheaper buy day is only
  useful for *future* sell days, so we check profit before updating the minimum.

This greedy approach works because the only thing that matters for maximizing profit on a given
sell day is the **lowest price that occurred before it** — we never need to consider any other
historical price.

Edge cases handled:
- **Empty array**: returns `0` immediately (no days to trade on).
- **Single-element array**: loop never executes since there's no second day to sell on; returns `0`.
- **Strictly decreasing prices**: `maxProfit` never gets updated above `0`.
- **Flat prices** (all equal): every `profitIfSoldToday` is `0`, so result stays `0`.

## Complexity

| Metric | Complexity | Explanation |
|--------|------------|--------------|
| Time   | O(n)       | Single pass through the `prices` array |
| Space  | O(1)       | Only two extra variables (`minPriceSoFar`, `maxProfit`) are used |

## Build Instructions

```bash
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

## Expected Output

```
Input: [7,1,5,3,6,4] -> Output: 5 | Expected: 5  [PASS]
Input: [7,6,4,3,1] -> Output: 0 | Expected: 0  [PASS]
Input: [] -> Output: 0 | Expected: 0  [PASS]
Input: [5] -> Output: 0 | Expected: 0  [PASS]
Input: [2,2,2,2] -> Output: 0 | Expected: 0  [PASS]
Input: [1,2] -> Output: 1 | Expected: 1  [PASS]
Input: [2,4,1,7] -> Output: 6 | Expected: 6  [PASS]
```

## Test Cases

| # | Input                | Expected Output | Notes                                  |
|---|-----------------------|------------------|-----------------------------------------|
| 1 | `[7,1,5,3,6,4]`       | `5`              | Standard case from problem statement    |
| 2 | `[7,6,4,3,1]`         | `0`              | Strictly decreasing prices — no profit  |
| 3 | `[]`                  | `0`              | Empty input                             |
| 4 | `[5]`                 | `0`              | Only one day — no valid transaction     |
| 5 | `[2,2,2,2]`           | `0`              | Flat/constant prices                    |
| 6 | `[1,2]`               | `1`              | Simple two-day increase                 |
| 7 | `[2,4,1,7]`           | `6`              | Best buy point isn't the first day      |