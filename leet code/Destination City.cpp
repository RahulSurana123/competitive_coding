

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given the array paths, where paths[i] = [cityAi, cityBi] means 
there exists a direct path going from cityAi to cityBi. Return the destination city, 
that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, 
therefore, there will be exactly one destination city.


    ***********************************************************
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int> m;
        for(auto x: paths){
            m[x[0]]++;
            if(!m.count(x[1]))m[x[1]] = 0; 
        }
        for(auto x: m){
            if(x.second==0) return x.first;
        }
        return "";
    }
};