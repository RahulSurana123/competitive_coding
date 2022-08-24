

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Geek and his classmates are playing a prank on their Computer Science teacher. 
They change places every time the teacher turns to look at the blackboard. 

Each of the N students in the class can be identified by a unique roll number X and each 
desk has a number i associated with it. Only one student can sit on one desk. 
Each time the teacher turns her back, a student with roll number X sitting on desk number 
i gets up and takes the place of the student with roll number i.

If the current position of N students in the class is given to you in an array, 
such that i is the desk number and a[i] is the roll number of the student sitting on the desk, 
can you modify a[ ] to represent the next position of all the students ? 

    ***********************************************************
*/


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    void prank(long long a[], int n){
        for(int i = 0 ; i < n ;i++){
            a[i] = a[i] + ((a[a[i]]%n)*n);
        }
        for(int i = 0 ; i < n ;i++){
            a[i] = a[i]/n;
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long a[n];
        for(int i = 0 ;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        ob.prank(a,n);

        for(int i = 0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}

  // } Driver Code Ends