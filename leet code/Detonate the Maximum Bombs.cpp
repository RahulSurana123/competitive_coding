

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. 
This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. 
xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. 
These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    bool v[101];

    bool d(long i,long j, long r){
        return  ((i*i)+(j*j)) <= r*r;
    }

    int df(int &i,vector<vector<int>>& b){
        v[i] = true;
        int a = 0;
        for(int k = 0; k < b.size(); k++){
            if(k==i) continue;
            if(!v[k] && d(b[i][0]-b[k][0],b[i][1]-b[k][1],b[i][2])) a += df(k,b); 
        }
        return a+1;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        // v.resize(bombs.size(), false);
        int ans = 1;
        for(int i = 0; i < bombs.size(); i++){
            ans = max(ans,df(i, bombs));
            memset(v,0,sizeof(bool)*101);
        }
        return ans;
    }
};