# Valid Palindrome

## What was asked

Given a string `s`, determine whether it is a palindrome after:
- converting all uppercase letters to lowercase, and
- removing all non-alphanumeric characters.

Return `true` if it reads the same forwards and backwards under those
rules, `false` otherwise.

*(This is [LeetCode 125 — Valid Palindrome](https://leetcode.com/problems/valid-palindrome/).)*

### Example
```
Input:  s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Input:  s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Input:  s = " "
Output: true
Explanation: After removing non-alphanumeric characters, s becomes "",
which reads the same forward and backward (it's an empty string).
```

## Approach

A **two-pointer** scan from both ends toward the middle, done in a single
pass with no extra string allocation:

1. Start `left` at index `0` and `right` at the last index.
2. Advance `left` forward past any non-alphanumeric characters
   (`isalnum` check), and move `right` backward past any
   non-alphanumeric characters.
3. Compare `tolower(s[left])` with `tolower(s[right])`. If they differ,
   the string isn't a palindrome — return `false` immediately.
4. Otherwise, move both pointers inward (`left++`, `right--`) and repeat.
5. If the pointers cross (`left >= right`) without ever finding a
   mismatch, the string is a palindrome — return `true`.

This runs in **O(n)** time (each character is visited a constant number
of times) and **O(1)** extra space, since it works directly on the input
string's characters rather than building a cleaned-up copy.

## Files
- `valid_palindrome.cpp` — the `Solution` class plus a small test driver
  with `main()` that runs it against the standard LeetCode examples and a
  few edge cases (empty string, single character pair, mixed case with
  punctuation).

## Build & run

```bash
g++ -O2 -o solution valid_palindrome.cpp
./solution
```

Expected output:
```
Input:    "A man, a plan, a canal: Panama"
Output:   true
Expected: true
PASS

Input:    "race a car"
Output:   false
Expected: false
PASS

Input:    " "
Output:   true
Expected: true
PASS

Input:    ""
Output:   true
Expected: true
PASS

Input:    "0P"
Output:   false
Expected: false
PASS

Input:    "Was it a car or a cat I saw?"
Output:   true
Expected: true
PASS
```