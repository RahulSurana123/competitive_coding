

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. 
Two subsets are different if and only if the chosen indices to delete are different.


    **********************The Number of Beautiful Subsets*************************************
*/


class Solution {
public:
    unordered_map<int,int> a;

    int df(int i,vector<int>& nums, int &k){
        if(i==nums.size()) {
            return 1; 
        }
        int t = 0;
        if(!a[nums[i]-k] && !a[nums[i]+k]){
            a[nums[i]]++;
            t = df(i+1,nums,k);
            a[nums[i]]--;
        }
        int nt = df(i+1,nums,k);
        return nt+t;
    }

    int beautifulSubsets(vector<int>& nums, int &k) {
        return df(0,nums,k)-1;
    }
};