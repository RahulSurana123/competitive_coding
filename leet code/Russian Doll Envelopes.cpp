

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    // int dp[100001];
    // int v[100001];
    
    // int df(int h, int w,int i, vector<vector<int>>& envelopes){
    //     if(i >= envelopes.size()) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int ans = 0;
    //     cout << i<<" -> "<<w<<" "<<h<<"\n";
    //     for(int k = 0; k < envelopes.size(); k++){
    //         if(h < envelopes[k][1] && w < envelopes[k][0]) {
    //             ans = max(ans,df(envelopes[k][1],envelopes[k][0],k+1,envelopes)+1);
    //         }
    //     }
    //     cout << i<<" "<<ans<<"\n";
    //     return dp[i] = ans;
    // }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp;
        sort(envelopes.begin(),envelopes.end(),[&](vector<int> &a, vector<int> &b){
            // if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
            // return a[0]*a[1] < b[0]*b[1];
        });
        for(int i = 0 ; i < envelopes.size(); i++){
            auto x = lower_bound(dp.begin(),dp.end(),envelopes[i][1]);    
            if(x == dp.end()) {
                    dp.push_back(envelopes[i][1]);
            }
            else if(envelopes[i][1] < *x){
                *x = envelopes[i][1];
            }
            cout << dp[dp.size()-1]<<"\n";
        }
        return dp.size();
    }
};