

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trip[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.


    ***********************************************************
*/


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> v(1001,0);
        for(auto x: trips){
            v[x[1]]+=x[0];
            v[x[2]]-=x[0];    
        }
        // sort(v.begin(),v.end());
        int s = 0;
        for(int i = 0; i < 1001;i++){
            s+=v[i];
            if(s>capacity) return false;
        }
        return true;
    }
};