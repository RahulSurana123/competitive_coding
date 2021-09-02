

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Chef found N magical cards in his drawer. Each card has a number written on each of its faces. He places all the cards on the table in a front face-up manner.

Chef denotes the numbers on the front face by A1,A2,...,AN and on the back face by B1,B2,...,BN. Chef can choose some (possibly zero or all) cards and flip them, 
then he will calculate the bitwise AND of all the numbers currently in a face-up manner.

Now Chef wonders what is the maximum bitwise AND that he can achieve and what is the minimum number of cards he has to flip to achieve this value. Can you help him find it?

Input Format:

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains three lines of input.
The first line contains a single integer N - the number of cards.
The second line contains N space-separated integers A1,A2,...,AN - the numbers on the front face of the cards
The third line contains N space-separated integers B1,B2,...,BN - the numbers on the back face of the cards

Output Format:

For each test case, print a single line containing two space-separated integers, first denoting the maximum bitwise AND 
possible and second denoting the minimum number of flips required to achieve it.



    ***********************************************************
*/



#include<bits/stdc++.h>
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

int main() {
 int t;
 cin>>t;
 while(t--){
    int n, ans = 0,nf = 0;
    cin >> n;
    vector<int> a(n), b(n);
    FOR(i,n) cin >> a[i];
    FOR(i,n) cin >> b[i];
    vector<int> inverted(n, -1);
    for(int i = 29; i >= 0; i--) {
        int iP = 1;
        for(int j = 0; j < n; j++) {
            if(inverted[j] != -1) {
                if(inverted[j] == 1) iP = ((iP&(b[j]>>i)&1));
                else iP = ((iP&(a[j]>>i)&1));
                continue;
            }
            if(((a[j]>>i)&1) || ((b[j]>>i)&1)) {}
            else { iP = 0; break; }
        }
        if(!iP) continue;
        int val = 1;
        
        for(int j = 0; j < n; j++) {
            if(inverted[j] != -1) {
            if(inverted[j] == 1) val = ((val&(b[j]>>i)&1));
            else val = ((val&(a[j]>>i)&1));
            }
            else{
                if (((a[j]>>i)&1) && ((b[j]>>i)&1)){}
                else if(((a[j]>>i)&1)) inverted[j] = 0;
                else if(((b[j]>>i)&1)) inverted[j] = 1, nf++;
                else {
                val = 0;
                break;
            }
        }
    }
        ans += (val * (1ll<<i));
    }
    cout << ans << " " << nf << '\n';
     
 }
 return 0;
}