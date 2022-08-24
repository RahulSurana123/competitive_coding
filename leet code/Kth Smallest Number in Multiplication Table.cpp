

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Nearly everyone has used the Multiplication Table. 
The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.



    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int s = 1, e = k;
        while(s<=e){
            int mid = s + (e-s)/2;
            int c = 0;
            int j = max(n,m);
            for(int i = 1 ; i <= min(n,m); i++){
                while(j > 0 && i*j > mid) j--;
                c += j;
            }
            // cout << mid <<" "<< c <<"\n";
            if(c >= k) e = mid - 1;
            else s = mid+1;
        }
        return s;
    }
};