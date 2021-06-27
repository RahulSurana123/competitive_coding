

/* 

    Solution by Rahul Surana

    ***********************************************************

We are playing the Guessing Game. The game will work as follows:

-> I pick a number between 1 and n.
-> You guess a number.
-> If you guess the right number, you win the game.
-> If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
-> Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.

Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.


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
#define MOD 1000000007 
using namespace std;

vector<vector<int>> dp;

int getMax(int l, int r){
    if(l>r) return INT_MIN;
    if(l==r) return 0; 
    if(l == r-1) return l;
    if(dp[l][r] != -1) return dp[l][r];
    int ans = INT_MAX;
    for(int i = l; i <= r; i++){
        int temp = max(i+getMax(l,i-1),i+getMax(i+1,r));
        ans = min(ans,temp);
    }
    return dp[l][r] = ans;
}


int main()
{
    fast_io;
    int n;
    cin >> n;
    dp.resize(201,vector<int>(201,-1));
    // cout << n << " ";
    cout << getMax(1,n);
}


// ### ATTEMPT 1


// vector<int> ar(201,0);
// int tree[4*201];

// void binaryCost(int s, int e,int ind){
//     if(s<=e) {        
//         int x = lower_bound(ar.begin()+s,ar.begin()+e,((ar[e])/2)) - ar.begin();
//         tree[ind] = x;
//         binaryCost(s,x-1,2*ind);
//         binaryCost(x+1,e,(2*ind)+1);
//         cout << tree[2*ind] <<" <- "<< tree[ind] << " -> " << tree[(2*ind)+1]<<"\n";
//     }
// }
    
// int tree_max(int root){
//         if(tree[2*root] == -1 &&  tree[(2*root) +1] == -1) return 0;
//         else if(tree[2*root] == -1) return root + tree_max((2*root) +1);
//         else if(tree[(2*root) +1] == -1) return root + tree_max((2*root));
//         else return root + max(tree_max(2*root),tree_max((2*root) +1));
// }
    
// int costTree(){
//     if(tree[2]!=-1 && tree[3]!=-1) return tree[1] + max(tree_max(2),tree_max(3));
//     else if(tree[2]!=-1) return tree[1] + tree_max(2);
//     else if(tree[3]!=-1) return tree[1] + tree_max(3);
//     else return tree[1];
// }
    
// int getMoneyAmount(int n) {
//     mem(tree,-1);
//     ar[0]=1;
//     for(int i = 1; i < n; i++){
//         ar[i] = ar[i-1]+i+1;
//     }
//     binaryCost(0,n-1,1);
//     return costTree();
// }
