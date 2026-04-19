

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given a circular array nums and an array queries.

For each query i, you have to find the following:

The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. 
If no such index exists, the answer for that query should be -1.
Return an array answer of the same size as queries, where answer[i] represents the result for query i.


    ***********************************************************
*/

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,int> ls;
        int n = nums.size();
        vector<int> md(n,n);
        vector<int> ans;
        for(int i = 0; i < n*2; i++){
            int t = i%n;
            if(ls.count(nums[t])){
                int pre = ls[nums[t]]%n;
                md[t] = min(md[t], (i-pre));
                md[pre] = min(md[pre], (i-ls[nums[t]])%n);
            }
            ls[nums[t]] = i;
        }
        for(int i = 0; i < queries.size(); i++){
            ans.push_back(md[queries[i]] == 0? -1: md[queries[i]]);
        }
        return ans;
    }
};
