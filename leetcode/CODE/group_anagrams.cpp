#include <algorithm>
#include <string> 
#include <vector> 
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
    public :
    vector<vector<string>> groupAnagram(vector<string>& strs){
        unordered_map <string ,vector<string>> mp;
        for(string s : strs){
            string key = s ; 
            sort(key.begin(),key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> result;
        for(auto & pair : mp)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
int main(){
    Solution sol;
    vector<string> strs = {"ate" , "tea","tan","ate", "nat" , "bat"};
    vector<vector<string>> result = sol.groupAnagram(strs);
    cout<<"Grouped Anagram"<<endl;

    for(auto group :result){
        cout<<"[";
        for(auto word : group)
        {
            cout<<word<<" ";
        }
        cout<<"]"<<endl;
    }
}