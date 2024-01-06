

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit 
north, south, east, or west, respectively. 
You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, 
if at any time you are on a location you have previously visited. Return false otherwise.


    ***********************************************************
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> s;

        int x = 0, y = 0;
        for(auto &q: path){
            s.insert({x,y});
            if(q == 'N'){
                y++;
            }
            else if(q == 'S'){
                y--;
            }
            else if(q == 'E'){
                x++;
            }
            else x--;
            if(s.count({x,y})) return true;
        } 
        return false;
    }
};