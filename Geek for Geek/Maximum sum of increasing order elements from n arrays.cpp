
/*

Solution by Rahul Surana

    ***********************************************************


Given n arrays of size m each. 
Find maximum sum obtained by selecting a number from each array such that 
the element selected from the i-th array is more than the element selected from (i-1)-th array. 
If maximum sum cannot be obtained then return 0.
 


    *********************************************************** 


*/



// { Driver Code Starts
// CPP program to find maximum sum
// by selecting a element from n arrays
#include<bits/stdc++.h>

using namespace std;

// To calculate maximum sum by
// selecting element from each array
int maximumSum( int n,int m, vector<vector<int>> &a);



// Driver program to test maximumSum
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
        cout << maximumSum(n,m,arr)<<endl;
    
    }
    return 0;

}
// } Driver Code Ends


int maximumSum( int n,int m, vector<vector<int>> &a) {

    for(int j = 0; j < n; j++){
        sort(a[j].begin(),a[j].end());
    }
    if(n==1) return a[0][m-1];
    int j = n-2;
    int val = a[n-1][m-1], sum = a[n-1][m-1];
    while(j >= 0){
        int k;
        for(k = m - 1; k >= 0 && a[j][k] >= val; k--){
        }
        if(k >= 0) { sum+=a[j][k]; val = a[j][k]; j--; }
        else return 0;
    }
    return sum;
}