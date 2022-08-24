


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Moamen has an array of n distinct integers. He wants to sort that array in non-decreasing order by doing the following operations in order exactly once:

Split the array into exactly k non-empty subarrays such that each element belongs to exactly one subarray.
Reorder these subarrays arbitrary.
Merge the subarrays in their new order.
A sequence a is a subarray of a sequence b if a can be obtained from b by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end.

Can you tell Moamen if there is a way to sort the array in non-decreasing order using the operations written above?

Input:

The first line contains a single integer t (1≤t≤103) — the number of test cases. The description of the test cases follows.
The first line of each test case contains two integers n and k (1≤k≤n≤105).
The second line contains n integers a1,a2,…,an (0≤|ai|≤109). It is guaranteed that all numbers are distinct.
It is guaranteed that the sum of n over all test cases does not exceed 3⋅105.

Output:

For each test case, you should output a single string.
If Moamen can sort the array in non-decreasing order, output "YES" (without quotes). Otherwise, output "NO" (without quotes).
You can print each letter of "YES" and "NO" in any case (upper or lower).



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

int ar[100001];
int ind[100001];

bool compare(int a, int b){
    return ar[a] < ar[b];
}

int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        FOR(i,n) { cin >> ar[i]; ind[i] = i; }
        // FOR(i,n) cout << ind[i] << "  ";
        // cout <<"\n";
        sort(ind,ind+n,compare);
        // FOR(i,n) cout << ind[i] << " ";
        // cout <<"\n"; 
        int count = 1;
        FOR(i,n-1){
            if(ind[i+1] != ind[i]+1){ count++; }
        }
        if(count <=k) cout << "YES\n";
        else cout << "NO\n";
    }
}