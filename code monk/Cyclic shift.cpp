

/* 

    Solution by Rahul Surana

    ***********************************************************

A large binary number is represented by a string  of size A and N comprises of 0s and 1s. 
You must perform a cyclic shift on this string. The cyclic shift operation is defined as follows:

If the string A is [a0,a1,a2,...,a(n-1)], then after performing one cyclic shift, the string becomes [a1,a2,a3,...,a0].

You performed the shift infinite number of times and each time you recorded the value of the binary number represented by the string. 
The maximum binary number formed after performing (possibly 0) the operation is B. 
Your task is to determine the number of cyclic shifts 
that can be performed such that the value represented by the string A will be equal to B for the kth time.

Input format

First line: A single integer T denoting the number of test cases
For each test case:
First line: Two space-separated integers N and K 
Second line: A denoting the string

    ***********************************************************

*/



#include <bits/stdc++.h>
#define ll          unsigned long long int
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



ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    ll base = 1;
 
    ll len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}


void solve() {
    vector<int> index;
    ll n,k;
    cin >> n >> k;
    string s,copy;
    cin >> s;

    // copy2 = s;
    copy = s;
    // cout << s << "\n";
    for(ll i=0;i<30536;i++){
        // cout << "stoi(s) "<<stoi(s)<<" ";
        // ll a = binaryToDecimal(s);
        if(s >= copy){
            
            if ((bool)(s==copy)){
                index.push_back(i);
            }
            else { index.clear(); copy = s; index.push_back(i);}
            // m = a;
            // cout << "copy "<<copy<<" ";
            // cout << "a :" << a<<" ";
        }
        reverse(s.begin()+1, s.end());
        reverse(s.begin(), s.end());
    }
    cout << "copy "<< s<< "\n";
    // cout <<"after the max"<< s << "\n";
    // for (ll i = 0; i < n; i++){
    //     if ((bool)(s==copy)){
    //         index.push_back(i);
    //     }
    //     reverse(s.begin()+1, s.end());
    //     reverse(s.begin(), s.end());
        
    // }
    // cout << s << "\n";
     for (ll i = 0; i < index.size(); i++){ cout << index[i]<<" ";}
    ll x = (int)k/index.size();
    int y = k%index.size();
    cout <<"\n"<< index.size() <<" "<< x-1 <<" "<< n <<" "<< (x-1)*n<< " " << y <<"\n";
    if(x==0) cout << index[y-1] <<"\n";
    else if(y==0 && x!=0) cout <<((x-1)*n + index[index.size()-1]) << "\n";
    else cout << (x)*n + index[y-1] << "\n";
}

int tc;

int main() {
    fast_io;

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}