

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.

Return the array arr.


    ***********************************************************
*/

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>> ni;
        for(int i = 0; i < nums.size(); i++){
            ni[nums[i]].push_back(i);
        }
        vector<long long> ans(nums.size(),0);
        for(auto x: ni){
            long c = 0;
            for(int z = 1; z < x.second.size();z++){
                c += abs(x.second[0] - x.second[z]);
            }
            ans[x.second[0]] = c;
            long e =0, m = 1, d = 0;
            for(int z = 1; z < x.second.size();z++){
                e += (m*abs(x.second[z] - x.second[z-1]));
                d += ((x.second.size()-z)*abs(x.second[z] - x.second[z-1]));
                ans[x.second[z]] = (c - d +e);
                m++;
                // cout << d <<" ";
            }
            // cout<<"\n";
        }
        return ans;
    }
};
