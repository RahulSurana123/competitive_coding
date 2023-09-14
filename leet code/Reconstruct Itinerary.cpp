

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. 
Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.


    ***********************************************************
    
*/

class Solution {
public:

    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> m;
    vector<string> ans;
    void df(string cur){
        auto &z = m[cur];
        while(!z.empty()) { 
            auto x = z.top();
            z.pop();  
            df(x); 
        }
        
        ans.push_back(cur);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &x: tickets){
            m[x[0]].push(x[1]);
        }
        df("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};