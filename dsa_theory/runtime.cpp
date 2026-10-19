#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// A) Spell-check
int countMisspelled(const vector<string>& dict,
                    const vector<string>& text) {
    int count = 0;
    //Recipe 
// 1 Input sizes: n = number of dictionary words; m = number of text words.
// 2 Basic operation: Comparing two words using word == d.
    for (const string& word : text) {
        bool found = false;

        for (const string& d : dict) {
            // 3 Exact dominating line:  "if (word == d)"
            if (word == d) {
                found = true;
                break;
            }
        }
// 4 Number of executions: In the worst case, every text word is compared with every dictionary word, giving (m x n) comparisons.
// 5 Time function: T(n,m)=c_1+c_2m+c_3mn  The dominant term is (mn).
        if (!found)
            count++;
    }

    return count;
}

//6 the worst-case complexity is \(\Theta(mn)\).

// B) Autocomplete
// 1 Input size: (n) = number of dictionary words.
// 2 Basic operation: Checking whether a word starts with the prefix.

vector<string> suggest(const vector<string>& dict,
                       const string& prefix) {
    vector<string> result;

    for (const string& word : dict) {
        // 3 Exact dominating line: if (word.find(prefix) == 0)
        if (word.find(prefix) == 0)
            result.push_back(word);
    }
// 4 Number of executions: The condition is checked once per dictionary word, so it executes \(n\) times. Each check can take up to \(p\) character comparisons, where \(p\) is the prefix length.
// 5 Number of executions: The condition is checked once per dictionary word, so it executes \(n\) times. Each check can take up to \(p\) character comparisons, where \(p\) is the prefix length.
// 6 Time function:T(n)=c_1+c_2n+c_3np

// Here, \(p\) is the prefix length. If prefix length is treated as bounded, this simplifies to \(T(n)=c_1+c_2n\).

// T(n)=O(n)} Assuming a bounded prefix length, the complexity is more precisely \(\Theta(n)\). The output vector also requires space proportional to the number of matching words.
    return result;
}
