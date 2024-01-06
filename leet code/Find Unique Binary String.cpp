

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of strings nums containing n unique binary strings each of length n, 
return a binary string of length n that does not appear in nums. 
If there are multiple answers, you may return any of them.


    ***********************************************************
*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for(int i = 0; i < nums.size(); i++){
            ans += nums[i][i] == '0'?"1":"0";
        }
        return ans;
    }
};