

/* 
    Solution by Rahul Surana
    
    ***********************************************************

There are some robots and factories on the X-axis. You are given an integer array robot where robot[i] is the position of the ith robot. You are also given a 2D integer array factory where factory[j] = [positionj, limitj] indicates that positionj is the position of the jth factory and that the jth factory can repair at most limitj robots.

The positions of each robot are unique. The positions of each factory are also unique. Note that a robot can be in the same position as a factory initially.

All the robots are initially broken; they keep moving in one direction. The direction could be the negative or the positive direction of the X-axis. When a robot reaches a factory that did not reach its limit, the factory repairs the robot, and it stops moving.

At any moment, you can set the initial direction of moving for some robot. Your target is to minimize the total distance traveled by all the robots.

Return the minimum total distance traveled by all the robots. The test cases are generated such that all the robots can be repaired.

Note that

All robots move at the same speed.
If two robots move in the same direction, they will never collide.
If two robots move in opposite directions and they meet at some point, they do not collide. They cross each other.
If a robot passes by a factory that reached its limits, it crosses it as if it does not exist.
If the robot moved from a position x to a position y, the distance it moved is |y - x|.


    ***********************************************************
*/

class Solution {
public:

    vector<vector<long long>> dp;
    const long long INF = 1e15;

    long long df(int i,int j, vector<int>& r, vector<vector<int>>& f){
        if(i == r.size()){
            return 0LL;
        }
        if(j==f.size()) return 1e18;
        if(dp[i][j] != -1) return dp[i][j];
        long long ans = df(i,j+1,r,f);
        long long take = 0;
        for(int k = 0; k < f[j][1]; k++){
            if(i+k >= r.size()) break;
            take += abs(r[i+k] - f[j][0]); 
            long long nd = df(i+k+1,j+1,r,f);
            ans = min(ans,take + nd);
        }
        return dp[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        dp.resize(robot.size()+1,vector<long long>(factory.size()+1,-1));
        return df(0,0,robot,factory);
    }
};