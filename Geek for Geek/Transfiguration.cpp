

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Professor McGonagall teaches transfiguration at Hogwarts. 
She has given Harry the task of changing himself into a cat. 
She explains that the trick is to analyze your own DNA and change it into the DNA of a cat. 
The transfigure spell can be used to pick any one character from the DNA string, remove it and insert it in the beginning. 
Help Harry calculates minimum number of times he needs to use the spell to change himself into a cat.



    ***********************************************************
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {   
        if(A.length() != B.length()) return -1;
        map<int,int> x;
        for(int i = 0 ; i < A.length(); i++){
            x[A[i] - 'a']++;
            x[B[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){ if(x[i]) return -1; }
        int ans = 0,i=A.length()-1,j=A.length()-1;
        while(i>=0){
           // cout << A[i] <<" "<< B[j] <<" ";
            if(A[i] == B[j]) j--;
            else { ans++; }
            i--;
        }
        return ans;
    //  vector<vector<int>> L(A.length(),vector<int>(B.length(),0));
    //  for(int i = 0 ; i < A.length(); i++){
    //     for(int j = 0 ; j < B.length(); j++){
    //          if(i==0 || j== 0){
    //              if(A[i] == B[j]) L[i][j] = 1;
    //          }
    //          else if(A[i] == B[j]){
    //              L[i][j] = L[i-1][j-1]+1;
    //          }
    //          else{
    //              L[i][j] = max(max(L[i-1][j], L[i][j-1]),L[i-1][j-1]);
    //          }
    //      } 
    //  }
        
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends