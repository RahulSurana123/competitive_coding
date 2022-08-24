


/* 


    Solution by Rahul Surana
    
    ***********************************************************


Largest subset
You are given an array A and an array B, both of the same size N.
You have to choose a subset of indices from 1 to N, such that for any pair of indices (x, y) in the chosen subset, one of the following conditions holds:

Ax < Ay  and  Bx < By
Ax > Ay  and  Bx > By
Ax = Ay  and  Bx != By
Task

Determine the size of the largest subset you can choose such that one of the given conditions always holds.

Notes

1-based indexing is followed.
Set A is a subset of a set B if all elements of A are also elements of B.
Example

Assumptions

N = 3
A = {3, 3, 3}
B = {4, 5, 2}
Approach

You choose the subset of indices {1, 2, 3}.
For any pair of indexes in the chosen subset, one of the given conditions holds.
Therefore the answer is 3.

Function description

Complete the solve function provided in the editor. This function takes the following 3 parameters and returns the required answer:

N: Represents the size of the arrays A and B
A: Represents the array denoting A
B: Represents the array denoting B
Input format

Note: This is the input format you must use to provide custom input (available above the Compile and Test button).

The first line contains a single integer N denoting the size of the arrays A and B.
The second line contains N space-separated integers denoting array A.
The third line contains N space-separated integers denoting array B.
Output format

Print the size of the largest subset of indices that you can choose.



    ***********************************************************

*/

#include<bits/stdc++.h>
using namespace std;


int solve (int N, vector<int> A, vector<int> B) {
   vector<set<int>> d(N);
   // int j = 0, k = 0;
   // for(int i = 0; i < N; i++){
   //    if(B[j] < B[i]){
   //       j = i;
   //    }
   //    if(B[k]>B[i]){
   //       k = i;
   //    }
   // }
   //    for(int j = i+1; j < N; j++){
   //       if(A[i]< A[j] && B[i] < B[j]) {
   //          d[i].insert(j);
   //          d[j].insert(i);
   //       }
   //       else if(A[i] > A[j] && B[i] > B[j]){
   //          d[i].insert(j);
   //          d[j].insert(i);
   //       }
   //       else if(A[i] == A[j] && B[i] != B[j]){
   //          d[i].insert(j);
   //          d[j].insert(i);
   //       }
   //    }  
   // }
   // int ans = 0;
   // for(int i = 0; i < N; i++){
   //    ans = max((int)d[i].size(),ans);
   // }
   // set<int> ans;
   // for(int i = 0; i < N; i++){
   //    for()
   // }
   auto fun = [&](int a, int b){
      if(A[a]>A[b]) return true;
      return false;
   };
   sort(A.begin(),A.end(),fun);
   sort(B.begin(),B.end(),fun);
   // for(int i = 0; i < N; i++) cout << B[i]<<" ";
   // cout <<"\n";
   set<int> s;
   // s.insert(j);
   // s.insert(k);
   int ans = 0;
   for(int i = 0; i < N; i++){
      int x = 0;
      vector<int> lis;
      for(int j = i+1; j < N; j++){
         auto z = lower_bound(lis.begin(),lis.end(),B[j]);
         if(z == lis.end()){
            // s.insert(j);
            // x++;
            lis.push_back(B[j]);
         }
         else *z = B[j];
         if(A[i] == A[j] && B[i]!=B[j]){
            x++;
         //    // s.insert(j);
         //    // s.insert(i);
         }  
      }
      ans = max(ans,(int)lis.size()+x);
   }
   // for(auto x: s) cout << x <<" ";
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i_A = 0; i_A < N; i_A++)
    {
      cin >> A[i_A];
    }
    vector<int> B(N);
    for(int i_B = 0; i_B < N; i_B++)
    {
      cin >> B[i_B];
    }

    int out_;
    out_ = solve(N, A, B);
    cout << out_;
}