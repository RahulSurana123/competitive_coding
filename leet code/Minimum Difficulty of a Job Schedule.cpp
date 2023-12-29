

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You want to schedule a list of jobs in d days. 
Jobs are dependent (i.e To work on the ith job, you have to finish all the jobs j where 0 <= j < i).

You have to finish at least one task every day. 
The difficulty of a job schedule is the sum of difficulties of each day of the d days. 
The difficulty of a day is the maximum difficulty of a job done on that day.

You are given an integer array jobDifficulty and an integer d. 
The difficulty of the ith job is jobDifficulty[i].

Return the minimum difficulty of a job schedule. 
If you cannot find a schedule for the jobs return -1.


    ***********************************************************
*/

class Solution {
public:

    vector<vector<int>> dp;

    int df(int d, int i, vector<int>& jD){
        if(i == jD.size() && d == 0) return 0;
        if(i >= jD.size()) return 1e9;
        if(d <= 0) return 1e9;

        if(dp[d][i] != -1) return dp[d][i];

        int x = 1e9;
        int ma = 0;
        for(int j = i; j < jD.size(); j++){
            ma = max(ma,jD[j]);
            x = min(x, ma + df(d-1,j+1,jD));
        }
        return dp[d][i] = x;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        dp.resize(d+1,vector<int>(jobDifficulty.size(),-1));
        int ans = df(d,0,jobDifficulty);
        return ans >= 1e9 ? -1:ans;
    }
};