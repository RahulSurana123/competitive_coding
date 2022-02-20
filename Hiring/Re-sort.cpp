
/*


    
    Solution by Rahul Surana
    
(Solved 50% Only)
    ************************************************************************



Re-sort
You are given a permutation A of 1 to N with only even lengthed slopes. A slope is defined as a consecutively decreasing subarray.

Note: A subarray containing a single element is also considered a slope of length 1. For example, the sequence [5, 1, 4, 6, 2, 3] has 2 slopes of length 2, i.e., [5, 1] and [6, 2], and 2 slopes of length 1, i.e., [4] and [3].

Consider the following algorithm to sort the permutation:

re-sort(sequence A):
    while(A is not sorted in non decreasing order):
        partition A into minimum number of consecutive slopes
        for each slope with length > 1:
            reverse(slope)
Task

Determine the total number of times reverse() is called when the sequence A is passed to re-sort()

Note: An array b is a subarray of an array a if b can be obtained from a by deletion of several (possibly, zero, or all) elements from the beginning and several (possibly, zero, or all) elements from the end. In particular, an array is a subarray of itself.

Example

Assumptions

N = 2
A = [2, 1]
Approach

The given sequence has only 1 slope initially of length 2.
When it is passed to re-sort(), the slope [2, 1] is reversed.
Now the sequence becomes [1, 2].
Hence, the output is 1 as reverse() is called only 1 time.

Function description

Complete the reverseCount function provided in the editor. This function takes the following 2 parameters and returns the number of times reverse function would be called in re-sort():

N: Represents an integer denoting the length of the permutation
A: Represents an array of integers denoting the permutation

Input format:

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

The first line contains a single integer T which denotes the number of test cases. T also denotes the number of times you have to run the reverseCount function on a different set of inputs.
For each test case:
The first line contains a single integer N denoting the length of the permutation.
The second line contains N space-separated integers denoting the permutation.

Output format:

For each test case, print only one integer in a single line representing the number of times reverse() is called.




    **************************************************************************


*/




#include<bits/stdc++.h>
using namespace std;

long long reverseCount (int N, vector<int> A) {
   // Write your code here
//    vector<int> c;
//    for(int i = 0 ; i < N; i++){ c.push_back(i); }

//    sort(c.begin(),c.end(),[&](int a, int b){ return A[a]<A[b]; });
//    int i = 0;
//    for(auto x: c) cout << x <<" ";
    int ans = 0;
    // bool fl = false;
   while(true){
       bool f = false;
       int i = 0;
       int c = 1;
      //  vector<pair<int,int>> p;
    //    cout << "hi";
       while(i+1 < N){
           while(i+c < N && A[i+c-1] > A[i+c]) { c++; }
           if(c>1) {
                f = true;
               //  p.push_back({i,i+c});
               reverse(A.begin()+i,A.begin()+i+c);
               ans++;
               i = i+c-1;
            //    fl = true;
           }
           c = 1;
           i++;
       }
      //  for(auto x: p){
      //       reverse(A.begin()+x.first,A.begin()+x.second);
      //       ans++;
      //       // cout << x.first <<" "<< x.second<<"\n";
      //  }
    //    for(auto x: A) cout << x <<" ";
    //    cout << "\n";
    //    cout << i <<" ";
       if(!f) break;
   } 
//    for(auto x: A) cout << x <<" ";
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
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
            cin >> A[i_A];
        }

        long long out_;
        out_ = reverseCount(N, A);
        cout << out_;
        cout << "\n";
    }
}