

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Serval soon said goodbye to Japari kindergarten, and began his life in Japari Primary School.

In his favorite math class, the teacher taught him the following interesting definitions.

A parenthesis sequence is a string, containing only characters "(" and ")".

A correct parenthesis sequence is a parenthesis sequence that can be transformed into 
a correct arithmetic expression by inserting characters "1" and "+" between the original characters of the sequence. 
For example, parenthesis sequences "()()", "(())" are correct (the resulting expressions are: "(1+1)+(1+1)", "((1+1)+1)"), while ")(" and ")" are not. 
Note that the empty string is a correct parenthesis sequence by definition.

We define that |s| as the length of string s. A strict prefix s[1…l] (1≤l<|s|) of a string s=s1s2…s|s| is string s1s2…sl. 
Note that the empty string and the whole string are not strict prefixes of any string by the definition.

Having learned these definitions, he comes up with a new problem. He writes down a string s containing only characters "(", ")" and "?". 
And what he is going to do, is to replace each of the "?" in s independently by one of "(" and ")" to make all strict 
prefixes of the new sequence not a correct parenthesis sequence, while the new sequence should be a correct parenthesis sequence.

After all, he is just a primary school student so this problem is too hard for him to solve. 
As his best friend, can you help him to replace the question marks? If there are many solutions, any of them is acceptable.

Input:

The first line contains a single integer |s| (1≤|s|≤3⋅105), the length of the string.
The second line contains a string s, containing only "(", ")" and "?".

Output:

A single line contains a string representing the answer.
If there are many solutions, any of them is acceptable.
If there is no answer, print a single line containing ":(" (without the quotes).



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
    // int t;
    // cin >> t;
    // while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int op=0,cl=0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(') op++;
            else if(s[i] == ')') cl++;
        }
        if(cl > n/2 || op>n/2 || n%2 == 1) { cout << ":(";  return 0; }
        for(int i = 0; i <  s.length(); i++){
            if(op < n/2 && s[i] == '?') { s[i] = '('; op++;}
            else if(s[i] == '?') s[i] = ')';
        }
        stack<char> ss;
        for(int i = 0 ; i < n; i++){
            if(s[i] == '('){
                ss.push(s[i]);
            }
            else if(s[i] == ')'){
                if(ss.empty()) { cout << ":(";  return 0; }
                ss.pop();
                if( i != n-1 && ss.empty()) { cout << ":(";  return 0; }
            }
        }
        // if(ss.size()>0){
        //     cout <<":(";
        // }
        // else
        cout << s;
}
