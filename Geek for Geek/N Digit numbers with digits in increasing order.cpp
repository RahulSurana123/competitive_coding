

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer N, print all the N digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).


    ***********************************************************
*/


// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:

    void vec(vector<int>& ans, vector<int>& A, int N){
        int temp = 0, i = 0;
        while(i < N) { temp*=10; temp += A[i];  i++; }
        ans.push_back(temp);
    }

    void df(vector<int>& ans, vector<int>& A, int pos,int m, int N){
        if(pos<N){
            for(int i = m+1; i < 10; i++){
                A[pos] = i;
                df(ans,A,pos+1,i,N);
            }
        }
        else if(pos==N){
            vec(ans,A,N);
        }
    }
    
    vector<int> increasingNumbers(int N)
    {
        vector<int> ans;
        vector<int> A(N,0);    
        if(N==1){
            for(int i = 0; i < 10; i++) ans.push_back(i);
        }
        else df(ans,A,0,0,N);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}  // } Driver Code Ends