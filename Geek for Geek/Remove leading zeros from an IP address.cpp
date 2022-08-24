

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an IP address, remove leading zeros from the IP address. 
Note that our IP address here can be a little different. 
It can have numbers greater than 255. 
Also, it does not necessarily have 4 numbers. The count can be lesser/more.


    ***********************************************************
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        string ans;
        for(int i = 0; i < s.length();i++){
            string j;
            while(i<s.length() && s[i]!='.') j+=s[i++];
            int k = 0;
            while(k<j.length() && j[k] == '0') k++;
            if(k == j.length()) ans+='0';
            else ans+= j.substr(k,j.length()-k);
            // long long x = stoll(j);
            // ans += to_string(x);
            if(i!=s.length()) ans+='.';
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends