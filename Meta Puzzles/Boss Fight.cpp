

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There are N warriors, the i-th of which has a health of H[i]units and can deal D[i] units of damage per second. 
They are confronting a boss who has unlimited health and can deal B units of damage per second. 
Both the warriors and the boss deal damage continuously − 
for example, in half a second, the boss deals B/2 units of damage.

The warriors feel it would be unfair for many of them to fight the boss at once, 
so they'll select just two representatives to go into battle. 
One warrior i will be the front line, and a different warrior j will back them up. 
During the battle, the boss will attack warrior i until that warrior is defeated 
(that is, until the boss has dealt H [i] units of damage to them), 
and will then attack warrior j until that warrior is also defeated, at which point the battle will end. 
Along the way, each of the two warriors will do damage to the boss as long as they are undefeated.

Of course, the warriors will never prevail, but they'd like to determine the maximum amount of damage 
they could deal to the boss for any choice of warriors i and j before the battle ends.
Note: Your return value must have an absolute or relative error of at most 10 ^ −6to be considered correct.

Constraints
3 ≤ C ≤ 10^12
1 ≤ N ≤ 500,000
1 ≤ A[i] < B[i] ≤ C−1
1 ≤ K ≤ 10^12
 
Each test case's parameters will be formulated such that the correct answer for that case is at most 10^15.


    ***********************************************************
*/


#include <bits/stdc++.h>
using namespace std;


double df(int i, int j,int &N, vector<int> &H, vector<int> &D, double cm){
  double cd = 0;
  int cj = 0;
  for(int k = 0; k < N; k++){
      if(k == i || k == j) continue;
      double h1 = H[i], d1 = D[i], h2 = H[j], d2 = D[j], h3 = H[k], d3 = D[k];
      double d = h1*d1 + d3*h3 + max( h1*d3, h3*d1);
      double dd = h2*d2 + d3*h3 + max( h2*d3, h3*d2);
      if( cm < d ){
          return df(i,k,N,H,D,d);
      }
      else if(cm < dd){
        return df(k,j,N,H,D,dd);
      }
  }
  return cm; 
}


double getMaxDamageDealt(int N, vector<int> H, vector<int> D, int B) {
  /*vector<int> idx(N,0);
  std::iota(idx.begin(),idx.end(), 0);
  sort(idx.begin(),idx.end(), [&](auto a, auto b){ return H[a] < H[b]; });
  
  // sort(id.begin(),id.end(), [&](auto a, auto b){ return D[a] < D[b]; });
  
  double ans = 0.0;
  for(int i = N-1; i > max(N-3,0); i--){
    double t = H[idx[i]] / (double)B;
    double a = t*D[idx[i]];
    for(int j = 0; j < N; j++){
      if(i!=j){
        ans = max(ans, a + ((t+(H[idx[j]]/(double)B))* D[idx[j]]));
        // cout << i <<" "<< j <<" "<<a<<" "<<ans <<"\n";
      }
    }
  }*/
  
  return df(0,1,N,H,D,0)/B;
}