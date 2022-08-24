

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a positive integer X which is at most 108.

Find three distinct non-negative integers A,B,C that do not exceed 109 and satisfy the following equation:

(A∣B)&(B∣C)&(C∣A)=X
Here, ∣ denotes the bitwise OR operator and & denotes the bitwise AND operator.

It can be shown that a solution always exists for inputs satisfying the given constraints. 
If there are multiple solutions, you may print any of them.

Input Format:

The first line contains an integer T, the number of test cases. The description of T test cases follows.
Each test case consists of a single line containing one integer, X.

Output Format:

For each test case, print on a new line three different space-separated integers A,B,C.
Your output will be considered correct only if A,B,C are distinct non-negative integers not exceeding 109 that satisfy the equation given in the problem statement.
If there are multiple solutions, you may print any of them.



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
