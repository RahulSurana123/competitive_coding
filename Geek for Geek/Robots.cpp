

/* 
    Solution by Rahul Surana
    
    ***********************************************************



There are two kinds of bots A and B in a 1-D array. A bot can only move left while B can only move right. 
There are also empty spaces in between represented by #. But its also given that the bots cannot cross over each other.

Given the initial state and final state, we should tell if the transformation is possible.

NOTE: There can be many bots of the same type in a particular array. 



    ***********************************************************
*/


// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    string moveRobots(string s1, string s2){
        int i = 0, j = 0;
        while(i < s1.length() && j < s1.length()){
            if(s1[i] == '#') i++;
            else if(s2[j] == '#') j++;
            else if(s2[j] != s1[i] || (s1[i] == 'B' && i > j) || (s1[i] == 'A' && j > i)) return "No";
            else i++, j++;
        }
        return "Yes";
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends