


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string S containing lowercase english alphabet characters. 
The task is to calculate the number of distinct strings that can be obtained after performing exactly one swap.
In one swap,Geek can pick two distinct index i and j (i.e 1 < i < j < |S| ) of the string, 
then swap the characters at the position i and j.



    ***********************************************************
*/


// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
        long long n = S.length(),c=0;
        long long ans = (((n)*(n-1))/2ll);
        vector<long long> f(26,0);
        for(int i = 0; i < n; i++){
            f[S[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(f[i]>1){
                ans -= (f[i] *(f[i]-1))/2ll;
                c++;
            }
        }
        return c == 0 ? ans : ans+1;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends