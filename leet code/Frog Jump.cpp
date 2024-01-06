

/* 

    Solution by Rahul Surana
    
    ***********************************************************


A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. 
The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. 
Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.
    

    ***********************************************************
*/


class Solution {
public:
    set<int> s;
    vector<vector<int>> dp;
    bool df(int i,vector<int>& stones, int k){
        if(i >= stones.size()) return false;
        if(i == stones.size()-1) return true;
        if(dp[i][k] != -1) return dp[i][k];
        bool ans = false;
        // cout << i <<" "<<stones[i] <<" "<< k<<"\n";
        for(int j = 1; j <= k+1; j++){
            if(j+i >= stones.size()) continue;    
            if(stones[i+j]-stones[i] <  k-1 || stones[i+j]-stones[i] >  k+1) continue;
            if(stones[i+j]-stones[i] > 0)
            ans |= df(i+j,stones,stones[i+j]-stones[i]);
            if(ans) return true;
        }
        
        return dp[i][k] = ans; 
        // return false;
    }

    bool canCross(vector<int>& stones) {
        if(stones[1] - stones[0] != 1) return false;
        dp.resize(stones.size()+1,vector<int>(stones.size()+1,-1));
        // s = set<int>(stones.begin(),stones.end());
        return df(1,stones, 1);
    }
};