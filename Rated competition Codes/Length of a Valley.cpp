/*


Solution by Rahul Surana

***************************************************************************

Length of a valley
Max. score: 100
You are given an integer array A consisting of N elements. For each element, you are required to find the length of the valley that is defined as:

Let i be the current index and l and r be the leftmost and rightmost index satisfying this property A[l] > A[l + 1] > .... > A[i - 1] > A[i] < A[i + 1] < ... < A[r - 1] < A[r] , 
then (r - l + 1) is the length of the valley. Also, assume that if A is [7, 2, 1, 5, 7, 9], then the answer is [1, 2, 6, 3, 2, 1].

Explanation

A1 (7): The answer is 1 because there is no element to the left and in right 2 is smaller than 7.
A2 (2): A1>A2, therefore, the answer is 2
A3 (1): A1>A2>A3<A4<A5<A6, therefore, the answer is 6
A4 (5): A4<A5<A6, therefore, the answer is 3
A5 (7): A5<A6, therefore, the answer is 2
A6 (9): 7 is smaller than 9 and there is no element to the right, therefore, the answer is 1
Input format

The first line contains an integer T denoting the number of test cases. 
The first line of each test case contains an integer N denoting the number of elements in array A.
The second line of each test case contains N space-separated integers of array A.
Output format

Print T lines. For each test case, print N space-separated integers denoting the length of the valley for each index.


*******************************************************************************************

*/



#include <bits/stdc++.h>
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define FOR(i,a)     for(int i = 0; i < a; i++)
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

int ar[500001],ans[500001];
int n;
void binaryCal(int arr[], int s, int r) {
    if (r>=s) {
        int mid = s + (r - s)/2;
        ans[mid]=1;
        int k = mid;
        int l = mid;
        while((k-1) >= 0) {
            if(ans[k-1] == 0) { 
                if(ar[k-1] > ar[l]) { 
                    ans[mid]++; 
                    k--; 
                    l--;
                }
                    // else if(ar[k-1] < ar[l]) { ar[k-1]++; break; }
                else { break; }
            }
            else { if(ar[k-1] > ar[l]) ans[mid] += ans[k-1]; break; }
        }
        k = mid;
        l = mid;
        while((k+1) < n) { 
            if(ans[k+1] == 0) { 
                if(ar[k+1] > ar[l]) {
                    ans[mid]++; 
                    k++; 
                    l++;
                }
                    // else if(ar[k-1] < ar[l]) { ar[k-1]++; break; }
                else { break; }
            }
            else { if(ar[k+1] > ar[l]) ans[mid] += ans[k+1]; break;}
        }
        // cout << " l "<< l << " m "<< mid <<" r "<< r << " " << ans[mid];
        binaryCal(arr, s, mid-1);
        binaryCal(arr, mid+1, r);
    }
}
// int ind[500001];
// int p;
// int partition(int low, int high) 
// { 
//     int pivot = ar[ind[high]]; 
//     int i = (low - 1);
//     for (int j = low; j <= high - 1; j++) 
//     { 
//         if (ar[ind[j]] < pivot) 
//         { 
//             i++;
//             int t = ind[i];
//             ind[i] = ind[j];
//             ind[j] = t;  
//         } 
//     } 
//     int t = ind[i+1];
//     ind[i+1] = ind[high];
//     ind[high] = t; 
//     return i + 1; 
// } 

// void quickSort(int low, int high) {
//     if (low < high) { 
//         p = partition(low, high); 
//         quickSort(low, p - 1); 
//         quickSort(p + 1, high); 
//     } 
// } 

int main()
{
	fast_io;
    int t;
    cin >> t;
    FOR(i,t) {
        cin >> n;
        // mem(ans,1);
        FOR(j,n) { cin >> ar[j]; ans[j]=0;}
        // Atempt 5 n*logn target
        binaryCal(ans,0,n-1);

        FOR(j,n) cout << ans[j] <<" ";
        cout << "\n";

        // Atempt 1
        // FOR(j,n) {
        //     bool s = true, e = true;
        //     ans[j] = 1;
        //     for(int k = 0; k < max(n-j,j); k++) {
        //         if((j+k+1) < n && ar[j+k+1] > ar[j+k] && e) ans[j]++;
        //         else e = false; 
        //         if((j-k-1)>=0 && ar[j-k-1] > ar[j-k] && s) ans[j]++;
        //         else s = false;
        //         // cout << ans[j] << " ";
        //     }
        //     // cout << "\n";
        // }
        // Atempt 2
        // for(int j = 0; j < n; j++) {
        //     ans[j]=1;
        //     int k = j;
        //     int l = j,adc=0,adcc=0;
        //     bool ad = false;
        //         while((k-1) >= 0) { 
        //             if(ar[k-1] > ar[l]) { 
        //                 ans[j]++; 
        //                 k--; 
        //                 l--;
        //             }
        //             // else if(ar[k-1] < ar[l]) { ar[k-1]++; break; }
        //             else { break; }
        //         }
        //         k = j;
        //         l = j;
        //         while((k+1) < n && !ad) { 
        //             if(ar[k+1] > ar[l]) {
        //                 for(int m = 0; m + j < k + 1; m++) { 
        //                     ans[m+j]++; 
        //                     adc = m; 
        //                 }
        //                 k++; 
        //                 l++;
        //             }
        //             // else if(ar[k-1] < ar[l]) { ar[k-1]++; break; }
        //             else { ad = true; break; }
        //         }
        //         adcc+=adc;
        //         if((k+1) == n) ad = true;
        //         if(adcc==j) ad = false;
        //     if(k == n && l == n-1) break;
        // }
        // Atempt 3
        // quickSort(0,n-1);
        // for(int j = n-1; j >= 0; j--) {
        //     if(ind[j] > 0 && (ar[ind[j]]!=ar[ind[j]-1])) 
        //     ans[ind[j]] += ans[ind[j]-1];
        //     if(ind[j] < n-1 && (ar[ind[j]]!=ar[ind[j]+1])) 
        //     ans[ind[j]] += ans[ind[j]+1];
        //     ans[ind[j]] += 1;
        // }
        // Atempt 4
        // int k = 0, l = 1;
        // while(k < n-1) {
        //     int c = 1;
        //     while(ar[l]<ar[l-1] && l<n) { c++; l++; }
        //     while(k<=l) { ans[k] = c; k++; }
        //     c = 1;
        //     while(ar[l]<ar[l-1] && l<n) { c++; l++; }
        //     while(k<=l) { ans[k] += c; k++; }
        // }
        
    }    
}