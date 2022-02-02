

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array a1,a2,…,an consisting of integers from 0 to 9. A subarray al,al+1,al+2,…,ar−1,ar is good if the sum of elements of this subarray is equal to the length of this subarray (∑i=lrai=r−l+1).

For example, if a=[1,2,0], then there are 3 good subarrays: a1…1=[1],a2…3=[2,0] and a1…3=[1,2,0].

Calculate the number of good subarrays of the array a.

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains one integer n (1≤n≤105) — the length of the array a.

The second line of each test case contains a string consisting of n decimal digits, where the i-th digit is equal to the value of ai.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case print one integer — the number of good subarrays of the array a.



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


int main()
{
	fast_io;
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        vector<int> h(32, 0);
        int n = x;
        int k = 0;
        for(int i = 31; i >= 0; i--){
            h[i] = (n&(1<<i)) > 0;
            k += (n&(1<<i)) > 0;
        }
        int a=0,b=0,c=0;
        bool fa=false,fb=false,fc=false;
        for(int i = 31; i >= 0; i--){
            if(h[i] && !fa){
                b += (1<<i);
                c += (1<<i);
                fa = true; 
            }
            else if(h[i] && !fb){
                a+= (1<<i);
                c += (1<<i);
                fb = true;
            } 
            else if (h[i] && !fc){
                a+= (1<<i);
                b+=(1<<i);
                fc = true;
            }
            else if(h[i]){
                a+= (1<<i);
                b+=(1<<i);
                c+=(1<<i);
            }

        }
        if(k>=3) { cout << a <<" "<< b<<" " << c <<"\n"; }
        else if(k == 2){
            cout << a <<" " << (b|(1<<29)) <<" "<<c <<"\n";
        }
        else if(k == 1){
            cout << a <<" " << (b|(1<<29)) <<" "<<(c|(1<<28)) <<"\n";
        }
        else{
            cout << (a|(1<<27)) <<" " << (b|(1<<29)) <<" "<<(c|(1<<28)) <<"\n";
        }
    }
}
