

/* 
    Solution by Rahul Surana
    
    ***********************************************************


In the popular spreadsheets systems (for example, in Excel) the following numeration of columns is used. The first column has number A, the second — number B, etc. till column 26 that is marked by Z. Then there are two-letter numbers: column 27 has number AA, 28 — AB, column 52 is marked by AZ. After ZZ there follow three-letter numbers, etc.

The rows are marked by integer numbers starting with 1. The cell name is the concatenation of the column and the row numbers. For example, BC23 is the name for the cell that is in column 55, row 23.

Sometimes another numeration system is used: RXCY, where X and Y are integer numbers, showing the column and the row numbers respectfully. For instance, R23C55 is the cell from the previous example.

Your task is to write a program that reads the given sequence of cell coordinates and produce each item written according to the rules of another numeration system.

Input
The first line of the input contains integer number n (1 ≤ n ≤ 105), the number of coordinates in the test. Then there follow n lines, each of them contains coordinates. All the coordinates are correct, there are no cells with the column and/or the row numbers larger than 106 .

Output
Write n lines, each line should contain a cell coordinates in the other numeration system.


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
    int t=1;
    cin >> t;
    while(t--){
        
        string s;
        cin >> s;
        int i = 0;
        string out="";
        string a = "";
        while(i < s.length() && s[i] <= 'Z' && s[i] >= 'A') a+=s[i++];
        string b = "";
        while(i < s.length() && s[i] <= '9' && s[i] >= '0') b+= s[i++];
        
        if(i == s.length()){
            out+="R" + b +"C";
            ll x=0;
            for(int k = a.length()-1; k >= 0; k--) {x += (pow(26,(a.length()-k-1))*((a[k]-'A')+1)); }
            out += to_string(x);
        }
        else{
            string c = "";
            while(i < s.length() && s[i] <= 'Z' && s[i] >= 'A') c+=s[i++];
            string d = "";
            while(i < s.length() && s[i] <= '9' && s[i] >= '0') d+= s[i++];
            int y = stoi(d);
            int x = stoi(b);
            string e = "";
            while(y>0){
                int x = y%26;
                y = y/26;
                if(x==0) { y--; x = 26; } 
                e += (x-1 + 'A');
            }
            for(int k = e.length()-1;k>=0;k--) out += e[k];
            out+=b;
        } 
        cout << out <<"\n";
    }
}