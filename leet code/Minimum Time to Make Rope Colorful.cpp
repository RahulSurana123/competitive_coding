

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. 
Bob can remove some balloons from the rope to make it colorful. 
You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) 
that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.
 



    ***********************************************************
*/



class Solution {
public:
    
    
//     int df(int i,string colors, vector<int>& nt, char cc, int score){
//         if(i>=colors.length()) return 0;
        
//         if(dp[i] != -1){
//             return dp[i];
//         }
        
//         int x = INT_MAX;
        
//         if(colors[i] == cc){
//             x = min(nt[i] + df(i+1,colors,nt,cc,score),x);
//         }
//         else{
//             x = min(df(i+1,colors,nt,colors[i],score),nt[i] + df(i+1,colors,nt,cc,score+nt[i]));
//         }
        
//         return dp[i] = x;
//     }
    
    int minCost(string colors, vector<int>& neededTime) {
        char last = colors[0];
        int s = 0, ls = -1, ts = 0;
        for(int i = 0; i < colors.length();){
            while(i < colors.length() && colors[i] == last){
                ls = max(ls,neededTime[i++]);
            }
            ts += ls;
            if(i > colors.length()-1){
                break;
            }
            last = colors[i];
        
            ls = -1;
            
        }
        for(int i = 0; i < colors.size(); i++) s+= neededTime[i];
        return s-ts;
    }
};