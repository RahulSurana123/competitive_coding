

/* 

    Solution by Rahul Surana

    ***********************************************************

Suppose the population is divided into the age groups [1,10],[11,20],[21,30],…,[91,∞). 
The age groups are numbered from 1 to 10 and there are Xi people in age group i.

The COVID vaccine drive has started and people will be vaccinated in the decreasing order of their age groups. 
Suppose P people are vaccinated per day and if less than P people are left in an age group, 
then the remaining doses for that day are given to the people of immediate lower age group and the process for that day continues 
until the vaccines for that day are finished or the entire population has been vaccinated. 
The selection of a person from a given age group is done randomly.

Given X, P, and Chef’s age group G, tell the minimum and the maximum number of days will it take for Chef to get vaccinated.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, twelve integers G, P, X1,X2,…,X10.

Output

For each test case, output in a single line two space-separated integers, the minimum and maximum time required for Chef to get vaccinated.



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


int main()
{
    fast_io;
    
    int t;
    cin >> t;
    
    while(t--) {

        ll g,p;
        ll ar[10]; 
        cin >> g >> p ;
        FOR(i,10) {
            // int a; 
            cin >> ar[i]; 
            // if(i>0) ar[i] = ar[i-1] + a; else ar[i] =a; 
        }
        int sum = 0;
        int k = 1;
        int m = 1;
        for(int i = 9 ; i >= 0; i--){
            if(i+1 != g) sum+=ar[i];
            else { 
                k = (sum / p) + 1;
                int mod = sum%p;
                if(mod == 0){
                    if(p >= ar[i]) {
                        m = k;
                        break;
                    }
                    else {
                        int left = ar[i] - p;
                        m = k + left/p;
                        if(left%p) m++;
                    } 
                }
                else{
                    if(ar[i] > p-mod) { 
                        int left = ar[i] - (p-mod); 
                        m = k + left/p;
                        if(left%p) m++; 
                    }
                    else {
                        m = k;
                    }
                    
                }
                break;
            }
        }
        cout << k << " " << m << "\n";
    }
}