

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.


    ***********************************************************
*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size(),0);
        vector<int> freq(A.size()+1,0);
        int z = 0;
        for(int i = 0; i < A.size(); i++){
            freq[A[i]]++;
            if(freq[A[i]] == 2){
                z++;
            }
            freq[B[i]]++;
            if(freq[B[i]] == 2){
                z++;
            }  
            ans[i] = z;
        }
        return ans;
    }
};
