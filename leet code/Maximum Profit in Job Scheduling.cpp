

/* 
    Solution by Rahul Surana
    
    ***********************************************************


We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, 
        return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.


    ***********************************************************
*/

class Solution {
public:

    vector<int> dp;

    int df(int i,vector<vector<int>>& p,int l){
        if(i >= p.size()) return 0;
        // if(dp[i] != -1) return dp[i];
        int ans = 0;
        ans = max(ans,df(i+1,p,l));
        if(p[i][0] >= l) ans = max(ans,p[i][2] + df(i+1,p,p[i][1]) );
        cout << i << " " << l <<  " "<<ans<<"\n";
        return dp[i] = ans;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>>  interval(n);
        dp.resize(n+1, 0);
        for(int i = 0; i < n; i++){
            interval[i] = {startTime[i],endTime[i], profit[i]};
        }
        sort(interval.begin(),interval.end(),[](auto &a, auto &b){
            if(a[1]==b[1]){
                if(a[0]==b[0]) return a[2]>b[2];
                return a[0]<b[0];
            }
            return a[1]<b[1];
        });
        for(int i = 0;i < n; i++){
            auto z = upper_bound(interval.begin(), interval.begin() + i, interval[i][0], 
            [&](int time, const auto& in){ 
                return time < in[1]; 
            }) - interval.begin();
            dp[i+1] = max(dp[i], dp[z] + interval[i][2]);
        }
        return dp[n];
    }
};