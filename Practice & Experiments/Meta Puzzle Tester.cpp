

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There’s a circular train track with a circumference of C metres. 
Positions along the track are measured in metres, clockwise from its topmost point. 
For example, the topmost point is position 0, 1 metre clockwise along the track is position 1, 
and 1 metre counterclockwise along the track is position C−1.

A train with negligible length runs clockwise along this track at a speed of 1 metre per second, starting from position 0. 
After C seconds go by, the train will have driven around the entire track and returned to position 0, 
at which point it will continue going around again, with this process repeated indefinitely.

There are N tunnels covering sections of the track, 
the i-th of which begins at position A[i] and ends at position B[i](and therefore has a length of B[i] − A[i] metres). 
No tunnel covers or touches position 0 (including at its endpoints), 
and no two tunnels intersect or touch one another (including at their endpoints). 
For example, if there's a tunnel spanning the interval of positions [1,4], 
there cannot be another tunnel spanning intervals [2,3] nor [4,5].

The train’s tunnel time is the total number of seconds it has spent going through tunnels so far. 
Determine the total number of seconds which will go by before the train’s tunnel time becomes K.

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
      double d = max(h1*d1 + h1*d3 + d3*h3, h1*d1 + h3*d1 + d3*h3);
      double dd = max(h2*d2 + h2*d3 + d3*h3, h2*d2 + h3*d2 + d3*h3);
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

int main()
{
    // fast_io;
    long long N, C, K;
    cin >> N >> K;  // ll int result = gcd(865480988334076944, 181153058753871872);
    vector<int> A(N),B(N);
      // cout << yo <<"\n";
      // cout << fastexpo(18,6)<<"\n";

      for(int i = 0; i < N; i++){
          cin >> A[i] >> B[i];
      }
      // FOR(i,n){
      //     int a,b;
      //     cin >>a>>b;
      //     adj[a].pb(b);
      //     adj[b].pb(a);
      // }
      // dfs(0,-1);
      cout << getMaxDamageDealt(N,A,B,K)<<"\n";
}