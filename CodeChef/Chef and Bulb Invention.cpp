


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Chef is trying to invent the light bulb that can run at room temperature without electricity. So he has N gases numbered from 0 to N−1 that he can use and he doesn't know which one of the N gases will work but we do know it.

Now Chef has worked on multiple search algorithms to optimize search. For this project, he uses a modulo-based search algorithm that he invented himself. 
So first he chooses an integer K and selects all indices i in increasing order such that imodK=0 and test the gases on such indices, then all indices i in increasing order such that imodK=1, and test the gases on such indices, and so on.

Given N, the index of the gas p that will work, and K, find after how much time will he be able to give Chefland a new invention assuming that testing 1 gas takes 1 day.

For example, consider N=5,p=2 and K=3.

On the 1st day, Chef tests gas numbered 0 because 0mod3=0.
On the 2nd day, Chef tests gas numbered 3 because 3mod3=0.
On the 3rd day, Chef tests gas numbered 1 because 1mod3=1.
On the 4th day, Chef tests gas numbered 4 because 4mod3=1.
On the 5th day, Chef tests gas numbered 2 because 2mod3=2.
So after 5 days, Chef will be able to give Chefland a new invention

Input Format:

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers N, p, and K.

Output Format:

For each test case, print a single line containing one integer — after how much time Chef will be able to give Chefland a new invention assuming that testing 1 gas takes 1 day.



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

int main()
{
    fast_io;
    int t;
    cin >> t;
    while(t--) {
        
        int n,p,k;
        cin >> n >> p >> k;
        int x = p%k;
        int m = (n)%k;
        int sum = 0;
        // for(int j = 0; j < k; j++){
        //     for(int i = j; i < n; i+=k){
        //         cout << i << " ";
        //     }
        // }
        cout << "\n";
        if(x == 0) sum+=ceil((p)/k)+1; 
        else{
            if(x<=m) { sum += (x)*(ceil((n)/k)+1); sum+=ceil((p)/k)+1; }
            else { sum += (m)*(ceil((n)/k)+1); sum += (x-m)*(ceil((n)/k)); sum+=ceil((p)/k)+1; }
            
        }
        cout << sum <<"\n";

    }
}