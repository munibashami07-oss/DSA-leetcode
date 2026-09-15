# Longest Substring Without Repeating Characters (LeetCode 3)

## Problem Statement

Given a string `s`, find the length of the longest substring without duplicate characters.

**Example 1:**
```
Input:  s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Note that "bca" and "cab" are also correct answers.
```

**Example 2:**
```
Input:  s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**
```
Input:  s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

## Visual Example

```
s = "abcabcbb"
     0123456 7

Sliding window (two pointers: left, right) grows right and shrinks left
on repeat, tracking the last index each character was seen at:

right=0 'a': window=[a]           len=1  lastSeen{a:0}
right=1 'b': window=[a,b]         len=2  lastSeen{a:0,b:1}
right=2 'c': window=[a,b,c]       len=3  lastSeen{a:0,b:1,c:2}  <- max so far
right=3 'a': 'a' seen at 0 >= left(0) -> left moves to 1
             window=[b,c,a]       len=3  lastSeen{a:3,b:1,c:2}
right=4 'b': 'b' seen at 1 >= left(1) -> left moves to 2
             window=[c,a,b]       len=3
right=5 'c': 'c' seen at 2 >= left(2) -> left moves to 3
             window=[a,b,c]       len=3
right=6 'b': 'b' seen at 4 >= left(3) -> left moves to 5
             window=[c,b]         len=2
right=7 'b': 'b' seen at 6 >= left(5) -> left moves to 7
             window=[b]           len=1

Answer: 3 (e.g. "abc")
```

## Algorithm — Plain-Language Explanation

This is a **sliding window** problem — the two-pointer technique applied to a string, where
`left` and `right` mark the boundaries of a window that always contains **no repeating
characters**.

We use a hash map `lastSeen` to record the most recent index at which each character appeared.
Walking `right` across the string one character at a time:

1. Look up the current character `c` in `lastSeen`.
2. If `c` has been seen before **and** that occurrence is inside the current window
   (`lastSeen[c] >= left`), then the window contains a duplicate — shrink it by jumping `left`
   to just past that previous occurrence (`left = lastSeen[c] + 1`). This is the key insight
   that avoids re-scanning: we don't shrink one step at a time, we jump directly past the
   conflicting character.
3. Update `lastSeen[c]` to the current index `right`.
4. Update `maxLen` with the current window size (`right - left + 1`) if it's larger.

The check `lastSeen[c] >= left` matters because a character might have appeared earlier in the
string but *outside* the current window (already pushed out by an earlier shrink) — in that
case it's not actually a duplicate within our current window, so we must not move `left`
backwards.

Edge cases handled:
- **Empty string**: loop never executes, `maxLen` stays `0`.
- **All identical characters** (e.g. `"bbbbb"`): window always shrinks to size 1.
- **Single-character or whitespace strings**: handled the same as any other single character.
- **Repeat appearing before the current window** (e.g. `"tmmzuxt"`): guarded by the
  `lastSeen[c] >= left` check so `left` never moves backwards incorrectly.

## Complexity

| Metric | Complexity | Explanation |
|--------|------------|--------------|
| Time   | O(n)       | Each character is visited by `right` once; `left` only moves forward, never backward |
| Space  | O(min(n, m)) | Hash map stores at most one entry per distinct character, where `m` is the size of the character set |

## Build Instructions

```bash
g++ -std=c++17 -O2 -Wall -o solution solution.cpp
./solution
```

## Expected Output

```
Input: "abcabcbb" -> Output: 3 | Expected: 3  [PASS]
Input: "bbbbb" -> Output: 1 | Expected: 1  [PASS]
Input: "pwwkew" -> Output: 3 | Expected: 3  [PASS]
Input: "" -> Output: 0 | Expected: 0  [PASS]
Input: " " -> Output: 1 | Expected: 1  [PASS]
Input: "dvdf" -> Output: 3 | Expected: 3  [PASS]
Input: "abba" -> Output: 2 | Expected: 2  [PASS]
Input: "tmmzuxt" -> Output: 5 | Expected: 5  [PASS]
```

## Test Cases

| # | Input        | Expected Output | Notes                                                        |
|---|--------------|------------------|----------------------------------------------------------------|
| 1 | `"abcabcbb"` | `3`              | Standard case from problem statement — answer "abc"           |
| 2 | `"bbbbb"`    | `1`              | All identical characters                                       |
| 3 | `"pwwkew"`   | `3`              | Answer must be substring, not subsequence — "wke"              |
| 4 | `""`         | `0`              | Empty string                                                    |
| 5 | `" "`        | `1`              | Single whitespace character                                    |
| 6 | `"dvdf"`     | `3`              | Repeated char forces window jump, not just a simple shrink      |
| 7 | `"abba"`     | `2`              | Tests stale `lastSeen` index guarded by `lastSeen[c] >= left`   |
| 8 | `"tmmzuxt"`  | `5`              | Repeat ('t') appears before current window — must not move left backwards |