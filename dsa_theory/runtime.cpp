#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// A) Spell-check
int countMisspelled(const vector<string>& dict,
                    const vector<string>& text) {
    int count = 0;

    for (const string& word : text) {
        bool found = false;

        for (const string& d : dict) {
            if (word == d) {
                found = true;
                break;
            }
        }

        if (!found)
            count++;
    }

    return count;
}

// B) Autocomplete
vector<string> suggest(const vector<string>& dict,
                       const string& prefix) {
    vector<string> result;

    for (const string& word : dict) {
        if (word.find(prefix) == 0)
            result.push_back(word);
    }

    return result;
}