

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Problem Statement

 

Given an integer N having digits 1 to 9, you can perform the following step:

• Remove X digits from the beginning and Y digits from the end
 

Note:

• X and Y can be any non-negative integers.
• X+Y should be less than the number of digits in N. In other words, at least one digit should be there after the removal.
 

You need to find the number of distinct pairs of {X, Y}, such that, the integer remaining after the removal is divisible by K.

 

Note: Every time the operation is made on the original integer N and not on the modified integer.

 

 

Constraints

 

• 1 ≤ N ≤ 10^100000
• 3 ≤ K < 2000
• K is not a multiple of 2 or 5.
 

Input Format

 

• First line contains integer N.
• Second line contains an integer K.
 

Output Format

 

An integer, denoting the number of pairs.

 

Sample Input

 

147

7

 

Sample Output

 

3

 

Explanation of Sample

 

We have five possible pairs:

Pair 1: [X=0, Y=1]

Thus, we remove only 1 digit from the end. Hence, the number after removal = 14, which is divisible by K.

Pair 2: [X=0, Y=0]

Thus, we take all the digits. Hence, the number will be 147, which is divisible by K.

Pair 3: [X=2, Y=0]

Thus, we remove two digits from the start. Hence, the number after removal = 7, which is divisible by K.



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

// vector<vector<int>> dp;

// int df(int i, int j, int n, int k){
//     return 0;
// }


int main()
{
	fast_io;
    int t=1;
    // cin >> t;
    while(t--) {
        string n;
        int k;
        cin >> n; 
        cin >> k;
        int ans = 0;
        for(int i = 0; i < n.length(); i++){
            for(int j = 1; j<= n.length()-i; j++){
                long long z = stoll(n.substr(i,j));
                // cout << z <<" ";
                if(z%k == 0) ans++;
            }
        }
        cout << ans<<"\n";
    }
}
