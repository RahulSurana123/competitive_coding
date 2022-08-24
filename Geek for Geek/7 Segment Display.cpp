

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Using seven segment display, you can write down any digit from 0 to 9 using at most seven segments. 
Given a positive number N and then a string S representing a number of N digits. 
You have to rearrange the segments in this N digit number to get the smallest possible N digit number. 
This number can have leading zeros. You can not waste any segment or add any segment from your own. 
You have to use all of the segments of the given N digits.

Note: You can refer this diagram for more details



    ***********************************************************
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string sevenSegments(string S, int N) {
        int k = 0;
        for(int i = 0 ; i < N; i++){
            if(S[i] == '0') k += 6;
            else if(S[i] == '1') k += 2;
            else if(S[i] == '2') k += 5;
            else if(S[i] == '3') k += 5;
            else if(S[i] == '4') k += 4;
            else if(S[i] == '5') k += 5;
            else if(S[i] == '6') k += 6;
            else if(S[i] == '7') k += 3;
            else if(S[i] == '8') k += 7;
            else k += 5;
        }
        
        int x = k-(2*N);
        // cout << k <<" ";
        string ans;
        while(x>=4){
            if(ans.length()<N)
            ans += '0';
            x-=4;
        }
        while(ans.length()<N){
            if(x == 0){
                while(ans.length()<N) ans+='1';
                // ans+='1';
            }
            else if(x==1){
                while(ans.length()<N-1) ans+='1';
                ans+='7';
            }
            else if(x==2){
                while(ans.length()<N-1) ans+='1';
                ans+='4';
            }
            else if(x==3){
                while(ans.length()<N-1) ans+='1';
                ans+='2';
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout << ob.sevenSegments(S,N) << endl;
    }
    return 0;
}  // } Driver Code Ends