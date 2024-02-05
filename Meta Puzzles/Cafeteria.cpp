

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A cafeteria table consists of a row of N seats, numbered from 1 to N from left to right. 
Social distancing guidelines require that every diner be seated such that K seats to their left and K seats to their right 
(or all the remaining seats to that side if there are fewer than K) remain empty.

There are currently M diners seated at the table, the i-th of whom is in seat S[i]. 
No two diners are sitting in the same seat, and the social distancing guidelines are satisfied.

Determine the maximum number of additional diners who can potentially sit at the table without 
social distancing guidelines being violated for any new or existing diners, assuming that the existing 
diners cannot move and that the additional diners will cooperate to maximize how many of them can sit down.

Please take care to write a solution which runs within the time limit.


    ***********************************************************
*/


#include <bits/stdc++.h>
using namespace std;

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
  sort(S.begin(),S.end());
  
  long long ans = (S[0]-1) / (K+1);
  // cout << 0 <<" "<< ans <<"\n";
  for(int i = 1; i < M; i++){
      long long gap = S[i] - S[i-1] - K - 1;
      ans += gap / (K+1);
      // cout << i <<" "<< ans <<"\n";
  }
  ans += ((N - S[M-1]) / (K+1));
  // cout << M <<" "<< ans <<"\n";
  return ans;
}