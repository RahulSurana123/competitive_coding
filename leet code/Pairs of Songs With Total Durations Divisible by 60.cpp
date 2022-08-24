

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. 
Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.


    ***********************************************************
*/


class Solution {
public:
    
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        map<int, int> m;
        for(int i = 0; i < time.size(); i++){
            ans += m[(60-(time[i])%60)%60];
            // cout << m[(60-(time[i])%60)%60];
            m[time[i]%60]++;
        }
        return ans;
    }
};