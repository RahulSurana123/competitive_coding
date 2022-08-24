

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Petya is a big fan of mathematics, especially its part related to fractions. 
Recently he learned that a fraction  is called proper iff its numerator is smaller than its denominator (a < b) and that the fraction is called irreducible if its numerator and its denominator are coprime (they do not have positive common divisors except 1).

During his free time, Petya thinks about proper irreducible fractions and converts them to decimals using the calculator. 
One day he mistakenly pressed addition button (+) instead of division button (÷) and got sum of numerator 
and denominator that was equal to n instead of the expected decimal notation.

Petya wanted to restore the original fraction, but soon he realized that it might not be done uniquely. That's why he decided to determine 
maximum possible proper irreducible fraction a/b such that sum of its numerator and denominator equals n. 
Help Petya deal with this problem.

Input:

In the only line of input there is an integer n (3 ≤ n ≤ 1000), the sum of numerator and denominator of the fraction.

Output:

Output two space-separated positive integers a and b, numerator and denominator of the maximum possible proper irreducible fraction satisfying the given sum.



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

// int p[1001];


// void seive_of_erathros(){
//     p[0] = 0;
//     p[1] = 1;
//     for(int i = 2; i < 1000; i++){
//         p[i] = 1;
//         for(int j = i*i;j< 1000;j+=i){
//             p[i] = 0;
//         }
//     }
// }

int main()
{
	fast_io;
    // int t;
    // cin >> t;
    // while(t--) {
        int n;
        cin >> n;
        int a=0,b=1;
        for(int i = n-1; i>=1 && i>n-i; i--){
            if(__gcd(i,n-i) == 1){
                a = i; b=n-i;
            } 
        }
        cout << b << " "<< a<<"\n";
    // }
}
