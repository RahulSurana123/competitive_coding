

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a binary string S. You would like to make every character of S equal to '0'.

To achieve this goal, you are allowed to perform two types of operations on S:

Select a substring T of S of length 3 such that not all characters of T are the same 
(i.e, T must be one of "001", "010", "011", "100", "101" and "110"), and flip all its characters (convert '1' to '0' and '0' to '1').

Select a single character of S and flip it.

There is an extra constraint imposed on the operations: The first operation may be of either type, 
but no two consecutive operations are allowed to be of the same type.

Given S, find a way to convert all characters to '0' using at most |S| operations or report that it is impossible. It can be proved that 
if every character of S can be made '0', the conversion can be done using no more than |S| operations.

If multiple constructions exist, print any of them. In particular, note that you do not need to minimize the number of operations used; 
any conversion using no more than |S| operations will be accepted.

Input Format:

The first line contains a single integer T, denoting the number of testcases. The description of T testcases follows.
The first and only line of each testcase contains a string S.

Output Format:

For each testcase, first output a single line containing "YES" if it is possible to convert the string S to all '0'-s; otherwise print "NO".

If the answer is "YES", print the number of operations you are going to perform, X, on the second line.

Then, if X>0, print X+1 lines describing the operations performed formatted as follows:

The first line contains a single integer 1 or 2, denoting whether your first operation is of type 1 or type 2 respectively.
The next X lines describe the operations, where
If you perform a type 1 operation on the length 3 substring starting at position i, print i.
If you perform a type 2 operation on position i, print i.
Note that the operations alternate between types 1 and 2, with the first operation being of the type you specify.

The string is assumed to be zero-indexed, so a type 1 operation must satisfy 0≤i≤|S|−3 and a type 2 operation must satisfy 0≤i≤|S|−1.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

You will receive a 'Wrong Answer' verdict if any of the following happen:

The number of operations is more than |S|
A type 1 operation is applied on a substring whose characters are all the same
Any operation is performed at an invalid index (valid indices are mentioned above, in bold)




    ***********************************************************
*/


#include <bits/stdc++.h>
#define ll          long long
#define vl          vector<ll>
#define v          vector<int>
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
        string s,p="";
        cin >> s;
        ll ct1=count(s.begin(),s.end(),'1');
        if(ct1==0){
          cout<<"YES"<<endl;
          cout<<"0"<<endl;
          continue;
        }
        if(ct1==s.length() && ct1%2==0){
          cout<<"NO"<<endl;
          continue;
        }
        v a;
        ll ans=0;
        if(ct1%2==1){
          ans++;
          a.pb(2);
          ll temp1=s.find('1');
          s[temp1]='0';
          a.push_back(temp1);
        }
        else{
          a.pb(1);
        }
        ll j=0,temp3=0;

        ll zero=s.find('0');
        ll one=s.find('1');
        ll q=0;
        // cout<<zero<<" "<<one<<endl;
        if(zero-one>=3){
          if((zero-one)%2==1){
            for(ll o=zero;o<s.length();o++){
              if(s[o]=='1'){
                temp3=o;
                s[o]='0';
                break;
              }
            }
            if(temp3-(zero-1)==2){
              ans+=2;
              a.push_back(zero-1);
              a.push_back(zero);
            }
            else if(temp3-(zero-1)>2){
              a.pb(zero-1);
              a.pb(temp3);
              a.pb(zero-1);
              a.pb(zero-1);
              ans+=4;
            }
            s[zero-1]='0';
            for(ll k=zero-1;k>0;k=k-2){
              a.pb(k-2);
              a.pb(k);
              ans+=2;
            }
          }
          else{
            for(ll k=zero;k>0;k=k-2){
              a.pb(k-2);
              a.pb(k);
              ans+=2;
            }
          }
          // for(ll m=zero;m<s.length();)
          for(ll k=zero;k<s.length();k++){
            p="";
            if(s[k]=='1'){
              p+=s[k];
              for(q=k+1;q<s.length();q++){
                p+=s[q];
                if(s[q]=='1'){
                  break;
                }
              }
              if(p.length()==2){
                a.push_back(k-1);
                a.push_back(k-1);
                ans+=2;
              }
              else if(p=="101"){
                a.pb(k);a.pb(k+1);
                ans+=2;
              }
              else if(p.length()>3){
                a.pb(k);a.pb(q);a.pb(k);a.pb(k);
                ans+=4;
              }
            }
            s[k]='0';s[q]='0';
            p="";
          }
        }
        else{
          p="";
          // p+=s[0];
          // p+=s[1];p+=s[2];
          // if(p=="011"){
          //   a.pb(0);a.pb(0);
          // }
          // else if(p=="")
          for(ll i=0;i<s.length();i++){
            p="";
            if(s[i]=='1'){
              p+=s[i];
              for(q=i+1;q<s.length();q++){
                p+=s[q];
                if(s[q]=='1'){
                  break;
                }
              }
              if(p.length()==2){
                // a.push_back(k-1);
                // a.push_back(k-1);
                // ans+=2;
                if(i!=0){
                  a.pb(i-1);a.pb(i-1);
                }
                else{
                  a.pb(i);a.pb(i+2);
                }
                
              }
              else if(p=="101"){
                a.pb(i);a.pb(i+1);
                ans+=2;
              }
              else if(p.length()>3){
                a.pb(i);a.pb(q);a.pb(i);a.pb(i);
                ans+=4;
              }
            }
            s[i]='0';s[q]='0';

          }
        }

        cout<<"YES"<<endl;
        cout<<a.size()-1<<endl;
        for(ll i=0;i<a.size();i++){
          cout<<a[i]<<endl;
        }
    }
}
