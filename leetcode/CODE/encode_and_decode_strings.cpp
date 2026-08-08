#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (string &str : strs) {
            encoded += to_string(str.size()) + "#" + str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            // Find the '#'
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            // Extract the length
            int length = stoi(s.substr(i, j - i));
            // Move past '#'
            j++;
            // Extract the string
            result.push_back(s.substr(j, length));
            // Move to the next encoded string
            i = j + length;
        }
        return result;
    }
}; 

int main() {
    Solution sol;
    vector<string> strs = {"neet", "code", "love", "you", "", "hello#world", "3#3"};

    string encoded = sol.encode(strs);
    cout << "Encoded: " << encoded << endl;

    vector<string> decoded = sol.decode(encoded);
    cout << "Decoded: [";
    for (size_t k = 0; k < decoded.size(); k++) {
        cout << "\"" << decoded[k] << "\"";
        if (k != decoded.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Match: " << (strs == decoded ? "true" : "false") << endl;

    return 0;}