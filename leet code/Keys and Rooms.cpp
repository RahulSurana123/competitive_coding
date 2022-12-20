

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. 
Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, 
denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, 
return true if you can visit all the rooms, or false otherwise.

 



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> v(rooms.size(),false);
        queue<int> q;
        v[0] = true;
        for(auto x: rooms[0]) q.push(x);
        for(;!q.empty();){
            int x = q.front();
            q.pop();
            if(v[x]) continue;
            v[x] = true;
            for(auto z: rooms[x]) q.push(z);
        }
        for(int i = 1; i < rooms.size(); i++){
            if(!v[i]) return false;
        }
        return true;
    }
};