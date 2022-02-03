

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a positive integer N, return its corresponding column title as it would appear in an Excel sheet.
For N =1 we have column A, for 27 we have AA and so on.

Note: The alphabets are all in uppercase.


    ***********************************************************
*/


// { Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    string ExcelColumn(int N)
    {
        string e = "";
        while(N>0){
            int x = N%26;
            N = N/26;
            if(x==0) { N--; x = 26; } 
            e += (x-1 + 'A');
        }
        reverse(e.begin(),e.end());
        return e;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends