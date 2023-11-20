

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed array of strings garbage 
where garbage[i] represents the assortment of garbage at the ith house. 
garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of 
metal, paper and glass garbage respectively. 
Picking up one unit of any type of garbage takes 1 minute.

You are also given a 0-indexed integer array travel where travel[i] 
is the number of minutes needed to go from house i to house i + 1.

There are three garbage trucks in the city, each responsible for picking up one type of garbage. 
Each garbage truck starts at house 0 and must visit each house in order; 
however, they do not need to visit every house.

Only one garbage truck may be used at any given moment. 
While one truck is driving or picking up garbage, the other two trucks cannot do anything.

Return the minimum number of minutes needed to pick up all the garbage.


    ***********************************************************
*/

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g = 0, gi = 0, p = 0, pi = 0, m = 0, mi = 0;
        for(int i = 1; i < travel.size(); i++) travel[i] += travel[i-1];
        
        for(int i = garbage.size()-1; i >= 0; i--){
            for(int j = 0; j < garbage[i].length(); j++){
                if(garbage[i][j] == 'G'){
                    g++;
                    if(i>0)
                    gi = max(travel[i-1],gi);
                }
                else if(garbage[i][j] == 'P'){
                    p++;
                    if(i>0)
                    pi = max(travel[i-1],pi);
                }else{
                    m++;
                    if(i>0)
                    mi = max(travel[i-1],mi);
                }
                // cout << g << " "<<p<<" "<<m<<" "<<gi<<" "<<pi<<" "<<mi<<'\n'; 
            }
        }
        return m + p + g + gi + mi + pi;
    }
};