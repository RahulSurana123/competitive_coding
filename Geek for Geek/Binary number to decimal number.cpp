
/*

Solution by Rahul Surana

    ***********************************************************


Given a Binary Number B, find its decimal equivalent.

 


    ***********************************************************


*/




// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
        int binary_to_decimal(string str)
        {
            int ans = 0;
            for(int i = 0; i < str.length(); i++){
                if(str[i] == '1') ans += (1<<(str.length()-i-1));
            }
            return ans;
        }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
        string str;
        cin >> str;
        Solution ob;
        int  ans = ob.binary_to_decimal(str);
        cout << ans <<"\n";
    }
    return 0;
}  // } Driver Code Ends