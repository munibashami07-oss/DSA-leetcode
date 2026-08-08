// Hoop Jump
// You and your friend are playing a game with hoops. There are 
// N
// N hoops (where 
// N
// N is odd) in a row. You jump into hoop 
// 1
// 1, and your friend jumps into hoop 
// N
// N. Then you jump into hoop 
// 2
// 2, and after that, your friend jumps into hoop 
// N
// −
// 1
// N−1, and so on.

// The process ends when someone cannot make the next jump because the hoop is occupied by the other person. Find the last hoop that will be jumped into.

// Input
// The first line contains an integer 
// T
// T, the number of test cases. Then the test cases follow.
// Each test case contains a single line of input, a single integer 
// N
// N.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<"last hoop would be : "<<(N+1)/2<<endl;
    }
}