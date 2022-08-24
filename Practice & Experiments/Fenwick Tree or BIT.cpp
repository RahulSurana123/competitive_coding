

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Learning Fenwick Tree



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
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
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


int ar[100001];
map<int,int> m;
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

        FOR(i,n) { cin >> ar[i+1]; }
        BIT<int> b(n);
        ll ans = 0;
        for(int i = 1 ; i <= n; i++){
            ans += b.sum(ar[i],n);
            b.add(ar[i],1);
            b.bprint();
        }
        cout << ans <<"\n";
    }
}
