

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array time where time[i] denotes the time taken by the ith bus to complete one trip.

Each bus can make multiple trips successively; that is, the next trip can start immediately after completing the current trip. 
Also, each bus operates independently; that is, the trips of one bus do not influence the trips of any other bus.

You are also given an integer totalTrips, which denotes the number of trips all buses should make in total. 
Return the minimum time required for all buses to complete at least totalTrips trips.


    ***********************************************************
*/


#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
    
        long long l = time[0],r = 0;
        for(auto x: time){
            l = min(l,(long long)x);
            r = max(r,(long long)x);
        }
        r*=totalTrips;
        auto ct = [&](long long a){ long long c = 0; for(auto x: time){ c+=(a/x); } return c; };
        while(l<=r){
            long long m = (l+r)/2;
            auto z = ct(m);
            if(z>=totalTrips) { r = m-1; }
            else if(z < totalTrips){ l = m+1; }
        }
        return l;
    }
};