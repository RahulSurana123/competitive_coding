

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

    map<string,vector<string>> m;
    // vector<string> ans;
    vector<string> df(string cur){
        // if(cur )
        // cout << cur <<" --> ";
        vector<vector<string>> a;
        while(m[cur].size() != 0) {
            vector<string> temp; 
            string nc = m[cur][0];
            temp.push_back(nc); 
            m[cur].erase(m[cur].begin());  
            //  cout << cur <<" " << nc<<"\n";
            auto z = df(nc); 
            temp.insert(temp.end(),z.begin(),z.end());
            a.push_back(temp);
        }
        int i;
        for(i = 0 ; i < a.size(); i++) if(a[i].back() != cur) break;
        vector<string> tt;
        if(i<a.size()){
        tt = a[i];
        a.erase(a.begin()+i);
        sort(a.begin(),a.end());}
        vector<string> ans;
        for(auto s:a) ans.insert(ans.end(),s.begin(),s.end());
        if(tt.size()>0)
        ans.insert(ans.end(),tt.begin(),tt.end());
        return ans;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto x: tickets){
            m[x[0]].push_back(x[1]);
            // cout << x[0] <<" "<<x[1] <<" -> ";
        }
        for(auto x: m){
            sort(m[x.first].begin(),m[x.first].end());
        }
        auto ans = df("JFK");
        ans.insert(ans.begin(),"JFK");
        return ans;
    }
};