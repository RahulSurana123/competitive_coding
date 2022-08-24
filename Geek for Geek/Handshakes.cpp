


/* 


    Solution by Rahul Surana
    
    ***********************************************************


We have N persons sitting on a round table. Any person can do a handshake with any other person.



    ***********************************************************

*/


// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int count(int N){
        if(N%2 == 1) return 0;
        if(N == 0||N==2) return 1;
        int ans = 0;
        for(int i = 0; i < N; i+=2) ans +=  count(i)*count(N-2-i);
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends