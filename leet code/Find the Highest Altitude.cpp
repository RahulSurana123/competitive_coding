

/* 

    Solution by Rahul Surana
    
    ***********************************************************

There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude between points
i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.
 


    ***********************************************************
*/


class Solution {
public:
static constexpr auto fast_io =  [](){  std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL); };
    int largestAltitude(vector<int>& gain) {
        int ans = 0, c = 0;
        for(int i = 0 ; i < gain.size(); i++) ans = max(ans,c+=gain[i]);
        return ans;
    }
};