


/* 


    Solution by Rahul Surana
    
    ***********************************************************


Good strings selection
You are given an array A of N string consisting of lowercase English characters.

3 strings are selected from the given array of strings A. The selection is said to be "Good strings selection" if they share at least 1 common vowel.

Task

Determine the total number of ways of making "Good strings selection" from the given array of string A.

Notes

Assume 0-based indexing.
The vowels of small English alphabets are [ a, e, i, o, u ].
Example

Assumption

N = 4
A = [aei, aeo, aou, eou]
Approach

The "Good strings selection" are [ [ aie, aeo, aou ], [ aei, aeo, eou ], [ aeo, aou, eou ] ].
Therefore the answer is 3.

Function description

Complete the countWays function present in the editor. This function takes the following 2 parameters and returns the string answer:

N: Represents the length of string array of strings A
A: Represents the array of strings
Input format 

Note: This is the input format you must use to provide custom input (available above the Compile and Test button).

The first line contains a single integer T, which denotes the number of test cases. T also specifies the number of times you have to run the countWays function on a different input set.
For each test case:
The first line contains an integer N.
The next N lines contain a string.
Output format

For each test case in a new line, print the answer denoting the number of "Good strings selection" ways.



    ***********************************************************

*/


#include<bits/stdc++.h>
using namespace std;

long long nCr(long long n){
    return (n*(n-1)*(n-2))/(2*3);
}

long long countWays (int N, vector<string> A) {
    map<char,vector<int>> m;
//    int f[N][5];
   string z = "aeiou";
   for(int i = 0 ; i < N; i++){
       for(int j = 0 ; j < z.length(); j++){
        //    f[i][j] = 0;
            if(find(A[i].begin(),A[i].end(),z[j]) != A[i].end()) {
                m[z[i]].insert(i);
                // f[i][j] = 1;
            }
            // cout << f[i][j] <<" ";
       }
    //    cout << "\n";
   }
   long long ans = 0;
   ans += nCr(m['a'].size());
   ans += nCr(m['e'].size());
   ans += nCr(m['i'].size());
   ans += nCr(m['o'].size());
   ans += nCr(m['u'].size());
   
//    long long ans = 0;
//    for(int i = 0; i < N; i++){
//        for(int j = i+1; j<N;j++){
//            for(int k = j+1; k < N; k++){
//                for(int l= 0; l<5;l++){ 
//                     if(f[i][l] && f[j][l] && f[k][l]) {
//                         // cout << i <<" "<<j <<" "<<k<<" "<<l<<"\n";
//                         ans++;
//                         break;
//                     }
//                }
//            }
//        }
//    }
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<string> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }

        long long out_;
        out_ = countWays(N, A);
        cout << out_;
        cout << "\n";
    }
}