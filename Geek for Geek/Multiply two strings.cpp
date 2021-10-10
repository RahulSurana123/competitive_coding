

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two numbers as stings s1 and s2. Calculate their Product.



    ***********************************************************
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
class Solution{
  public:
  
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        string ans(n+m,'0');
        int i,j,k=0,l=0;
        if(s1[0] == '-') k++;
        if(s2[0] == '-') l++;
        for(i= n-1; i >= k; i--){
            for(j = m-1; j >= l; j--){
                int p = ((s1[i] - '0') * (s2[j] - '0')) + (ans[i+j+1]-'0');
                // cout << p << " ";
                ans[i+j+1] = p%10 + '0';
                ans[i+j] += p/10;
            } 
        }
        
        for(int i = 0; i < ans.length();i++){
            if(ans[i] != '0') { if(k ^ l) return '-' + ans.substr(i); else return ans.substr(i); }  
        }
        return "0";
    }

};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        cin>>a>>b;
        Solution obj;
        cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}  // } Driver Code Ends