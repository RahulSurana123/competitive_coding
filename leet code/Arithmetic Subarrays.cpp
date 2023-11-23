

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A sequence of numbers is called arithmetic if it consists of at least two elements, 
and the difference between every two consecutive elements is the same. 
More formally, a sequence s is arithmetic if and only if s[i+1] - s[i] == s[1] - s[0] for all valid i.

For example, these are arithmetic sequences:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9

The following sequence is not arithmetic:
1, 1, 2, 5, 7

You are given an array of n integers, nums, and two arrays of m integers each, l and r, 
representing the m range queries, where the ith query is the range [l[i], r[i]]. 
All the arrays are 0-indexed.

Return a list of boolean elements answer, 
where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to 
form an arithmetic sequence, and false otherwise.


    ***********************************************************
*/

class Solution {
public:

    bool df(vector<int> nums, int i, int j){
        if(i+1 == j) return true;
        vector<int> a(nums.begin()+i,nums.begin()+j+1);]
        sort(a.begin(),a.end());
        int dif = a[0] - a[1];
        for(int k = 1; k < a.size(); k++){
            if(a[k-1] - a[k] != dif) return false;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());
        for(int i = 0; i < l.size(); i++){
            ans[i] = df(nums,l[i],r[i]);
        }
        return ans;
    }
};