

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Petya has an array of integers a1,a2,…,an. He only likes sorted arrays. Unfortunately, the given array could be arbitrary, so Petya wants to sort it.

Petya likes to challenge himself, so he wants to sort array using only 3-cycles. More formally, in one operation he can pick 3 pairwise distinct indices i, j, and k (1≤i,j,k≤n) and apply i→j→k→i cycle to the array a. It simultaneously places ai on position j, aj on position k, and ak on position i, without changing any other element.

For example, if a is [10,50,20,30,40,60] and he chooses i=2, j=1, k=5, then the array becomes [50–––,40–––,20,30,10–––,60].

Petya can apply arbitrary number of 3-cycles (possibly, zero). You are to determine if Petya can sort his array a, i. e. make it non-decreasing.

Input:

Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤5⋅105). Description of the test cases follows.
The first line of each test case contains a single integer n (1≤n≤5⋅105) — the length of the array a.
The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n).
It is guaranteed that the sum of n over all test cases does not exceed 5⋅105.

Output:

For each test case, print "YES" (without quotes) if Petya can sort the array a using 3-cycles, and "NO" (without quotes) otherwise. You can print each letter in any case (upper or lower).


    ***********************************************************
*/


#include <bits/stdc++.h>
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define FOR(i,a)     for(int i = 0; i < a; i++)
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

template <typename T>
struct BIT{
    
    int N;
    vector<T> bit;
    
    BIT(int N): N(N), bit(N+1,0) { 
    }

    T sum(int i){
        T ans = 0;
        while(i>0){
            ans += bit[i];
            i -= (i & -i); 
        }
        return ans;
    }

    void add(int index, T num){
        while(index <= N){
            bit[index] += num;
            index += (index & -index);
        }
    }

    void bprint(){
        for(int i = 1; i <= N; i++){
            cout << bit[i] <<" ";
        }
        cout << "\n";
    }

    T sum(int l, int r){
        return sum(r) - sum(l);
    }
};


// vector<vector<int>> dp;
// int ans = 0;

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ar[n+1];
        vector<int> b(n);
        FOR(i,n) { cin >> ar[i+1]; b[i]= ar[i+1]; }
        sort(b.begin(),b.end());
        bool f = false;
        for(int i =1; i < n ; i++){
            if(b[i] == b [ i-1]) { f = true; break; }
        }
        if(f) { cout << "YES\n"; continue; }
        else {
            ll ans = 0;
            BIT<int> x(n+1);
            for(int i = 1; i <=n; i++){
                ans += x.sum(ar[i],n);
                x.add(ar[i],1);
            }
            cout << (ans%2 == 1? "NO": "YES") <<"\n";
        }
    }
}


