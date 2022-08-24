

/* 

    Solution by Rahul Surana

    ***********************************************************

Motu and Patlu are very good friends and they love to eat ice-creams. Once they thought of playing a game, so they bought “n” ice-creams from the market of varying heights (may be same). They arranged the ice-creams in a line in random order. Motu starts to eat ice-creams from left to right and Patlu from right to left. The heights of the ice-creams are known.

Motu eats the ice-cream as twice the speed of Patlu (that’s the secret for his health :p ). If, anyone of them is eating the ice-cream , then definitely other one cannot have that ice-cream. However, if both of them reach the same ice-cream, Motu snatches it away from Patlu (he got more power than patlu :( ) and eats it. The winner will be the one who will eat more number of ice-creams.

Since, both of them are too busy in eating ice-creams they forgot to count the number of ice-creams they have already eaten. Can you help them in deciding the winner.

P.S.- Since, ‘WINTER HAS ALREADY ARRIVED’ ,so ice-creams will not melt as it is freezing out there.

Note : Time taken to eat a ice-cream is directly proportional to its height.

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
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io     std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;
int inf=1e9+7, MOD=1e9+7;


string alph="abcdefghijklmnopqrstuvwxyz";
 
ll gcd(ll a,ll b){if(a==0) return b;else return gcd(b%a,a);}
ll bigpow(ll a,ll b){
    //Binary Exponentiation
    ll res=1;
    while(b>0)
    {
        if(b&1)
            res=res*a;//%mod;
        a=a*a;//%mod;
        b>>=1;
    }
    return res;
}
 
int main()  
{
    turbo;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >>arr[i];
        bool flag=true;
        int m=1,p=1;
        double motu[n]={0.0};
        motu[0]=(double)arr[0]/2.0;
        double patlu[n]={0.0};
        patlu[n-1]=(double)arr[n-1];
        for(int i=n-2;i>=0;i--)
            patlu[i]=arr[i];
        for(int i=1;i<n;i++)
            motu[i]=((double)arr[i]/2.0);
        int i=0,j=n-1;
        while(m+p<n)
        {
            
            if(motu[i]<patlu[j])
            {
                m++;
                i++;
                motu[i]+=motu[i-1];
            }
            else if(motu[i]>patlu[j])
            {
                p++;
                j--;
                patlu[j]+=patlu[j+1];
            }
            else
            {
                m++;
                p++;
                i++;
                j--;
                motu[i]+=motu[i-1];
                patlu[j]+=patlu[j+1];
 
            }
 
        }
        p=n-m;
        if(m>p)
        {
            cout << m <<" "<<p;
            cout << "\nMotu\n";
        }
        else if(m<p)
        {
            cout << m <<" "<<p;
            cout << "\nPatlu\n";
        }
        else
        {
            cout << m <<" "<<p;
            cout << "\nTie\n";
        }
 
    }
    return 0;
    
}