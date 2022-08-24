

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an unsorted array Arr of size N of positive integers. 
One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.



    ***********************************************************
*/


// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        set<int> s;
        int f = -1;
        long long su = 0;
        for(int i= 0; i < n; i++){
            if(s.count(*(arr+i))){
                f = *(arr+i);
            }
            else{
                s.insert(*(arr+i));
            }
            su += *(arr+i);
        }
        int k = (((long long)(n)*(long long)(n+1)/2)-(su-f));
        int* a;
        a = &f;
        (*(a+1)) = k;
        return a;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends