

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected directly with city c, 
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, 
and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:

    map<int,bool> vis;

    void df(int i, vector<vector<int>>& ic){
        if(vis[i]) return;
        vis[i] = true;
        // cout << i<< " "<<j<<"\n";
        for(int k = 0; k < ic[0].size(); k++){
            if(k != i && ic[i][k]) df(k,ic);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        for(int i = 0; i < isConnected.size(); i++){
                if(!vis[i]) { df(i,isConnected); ans++; }
        }
        return ans;
    }
};