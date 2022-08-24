

/* 

    Solution by Rahul Surana
    
    ***********************************************************


We stack glasses in a pyramid, where the first row has 1 glass, 
the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup of champagne.

Then, some champagne is poured into the first glass at the top.  
When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.  
When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  
(A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.  
After two cups of champagne are poured, the two glasses on the second row are half full.
After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  
After four cups of champagne are poured, the third row has the middle glass half full, 
and the two outside glasses are a quarter full, as pictured below.



Now after pouring some non-negative integer cups of champagne, 
return how full the jth glass in the ith row is (both i and j are 0-indexed.)



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    // vector<vector<double>> dp;
    
    
    //
    //          **********************************
    //              Top Down Approach
    //          **********************************
    
    // double df(int i, int j, int poured){
    //     if(j < 0 || j >= i+1 || i < 0) return 0.0;
    //     if(i == 0 && j == 0) return dp[i][j] = (double) poured;
    //     // if(i == 1) return dp[i][j] = (double)(poured-1)/2.0;
    //     if(dp[i][j] != -1.0) return dp[i][j];
    //     double y = df(i-1,j-1,poured);
    //     double z = df(i-1,j,poured);
    //     double x = (y>1? y-1: 0)/2 + (z>1?z-1:0)/2;
    //     cout << i << " "<< j<<" "<<x<<"\n";
    //     return dp[i][j] = x;
    // }
    
    double champagneTower(int poured, int query_row, int query_glass) {
        
        //
        //          **********************************
        //              Top Down Approach
        //          **********************************
        // dp.resize(query_row+2,vector<double>(query_glass+2,-1.0));
        // double x = df(query_row,query_glass,poured);
        // return x > 1 ? 1.0 : x;
        
        //
        //      *******************************
        //          Bottom Up Approach
        //      *******************************
        //
        // dp[0][0] = (double)poured;
        vector<double> dp(query_glass+2);
        dp[0] = (double)poured;
        for(int i = 1; i <= query_row; i++){
            vector<double> temp(query_glass+2);
            for(int j = 0; j <= query_glass ; j++){
                //
                //      *******************************
                //          Bottom Up Approach
                //      *******************************
                //
                // if(j == 0){
                //     dp[i][j] = (dp[i-1][j] > 1 ? (dp[i-1][j] - 1) : 0) / 2;
                // }
                // else{
                //     dp[i][j] = (dp[i-1][j] > 1 ? (dp[i-1][j] - 1) : 0) / 2 + (dp[i-1][j-1] > 1 ? (dp[i-1][j-1] - 1) : 0) / 2;
                //     // else {
                //     //       dp[i][j] = (dp[i-1][j] > 1 ? (dp[i-1][j] - 1) : 0) / 2 + (dp[i-1][j-1] > 1 ? (dp[i-1][j-1] - 1) : 0) / 2;
                //     // }
                // }
                if(j == 0){
                    temp[j] = (dp[j] > 1 ? (dp[j] - 1) : 0) / 2;
                }
                else{
                    temp[j] = (dp[j] > 1 ? (dp[j] - 1) : 0) / 2 + (dp[j-1] > 1 ? (dp[j-1] - 1) : 0) / 2;  
                }  
            }
            dp = temp;
        }
        // return dp[query_row][query_glass] > 1 ? 1.0 : dp[query_row][query_glass];
        return dp[query_glass] > 1?1.0: dp[query_glass];
    }
};