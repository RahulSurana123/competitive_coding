
/*


    
    Solution by Rahul Surana
    

    ************************************************************************



Given an array of size N containing positive integers n and a number k,
The absolute difference between values at indices i and j is |a[i] – a[j]|. 
There are n*(n-1)/2 such pairs and you have to print the kth smallest absolute difference among all these pairs.




    **************************************************************************



*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int kthDiff(int a[], int n, int k);

// Driver code
int main() {
    int t, i;
    int k;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;

        cout << kthDiff(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends


int kthDiff(int a[], int n, int k)
{
    sort(a,a+n);
    auto x = [&](int z){
        int c = 0;
        for(int i = 0; i < n; i++){
            c+=upper_bound(a+i,a+n,a[i]+z) - (a+i+1);
        }
        return c;
    };
    int l = -1;
    for(int i = 1 ; i < n ; i++){
        l = min(l, a[i] - a[i-1]);
    }
    int h = a[n-1] - a[0];
    while(h>l){
        int m = l + (h-l)/2;
        if(x(m) < k){
            l = m+1;
        }
        else h = m;
    }
    return l;
}