

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.


    ***********************************************************
*/


class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> p(n,0);
        p[0]=arr[0];
        for(int u = 1; u < n; u++){
            p[u] = arr[u]^p[u-1];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                for(int k = j; k < n; k++){
                    int l = p[j-1], r = p[k]^p[j-1];
                    if(i>0) l ^= p[i-1];
                    if(l == r) ans++;
                }
            }
        }
        return ans;
    }
};