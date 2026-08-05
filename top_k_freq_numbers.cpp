#include <iostream>
#include <queue>
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
    public : 
    vector<int> topffreq(vector<int>& nums , int k)
    {
        unordered_map<int,int> freq;
        for(int num : nums)
        {
            if(freq.find(num)==freq.end())
            {
                freq[num]=1;
            }
            else{
                freq[num]++;
            }
        }
        priority_queue<pair<int , int>> pq;
        for(auto p : freq){
            pq.push({p.second , p.first});
        }
    vector<int> result ;
    while(k--)
    {
        result.push_back(pq.top().second);
        pq.pop();
    }          
    return result ; 
    }
};
int main()
{
  Solution sol ;
  vector<int> nums = {1,2,3,1,2,3,1};
  int k = 2 ; 
  cout<<"Top "<<k<<" Frequent numbers"<<endl;
  vector<int>result= sol.topffreq(nums , k);
  for(int num : result)
  {
    cout<<num<<" ";
  }  
    return 0;
}