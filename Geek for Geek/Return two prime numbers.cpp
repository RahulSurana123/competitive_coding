

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an even number N (greater than 2), return two prime numbers whose sum will be equal to given number. 
There are several combinations possible. 
Print only the pair whose minimum value is the smallest among all the minimum values of pairs and print the minimum element first.

NOTE: A solution will always exist, read Goldbachs conjecture.



    ***********************************************************
*/


// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> seive_of_erathros(int N){
        vector<int> a(N+1,1);
        a[0] = 0;
        a[1] = 0;
        for(int i = 2; i * i <= N; i++ ){
            if(a[i]){
                for(int j = i*i; j <= N; j+=i){
                    a[j] = 0;
                }
            }
        }
        // FOR(i,N) if(a[i]) ar.pb(i);
        return a;
    }
    vector<int> primeDivision(int N){
        vector<int> x = seive_of_erathros(N);
        for(int i = 0; i < N; i++){
            if(x[i] && x[N-i]) return {i,N-i};
        }
        return {-1,-1};
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends