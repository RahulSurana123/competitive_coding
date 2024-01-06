



/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a directed graph of n nodes numbered from 0 to n - 1, 
where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, 
indicating that there is a directed edge from node i to node edges[i]. 
If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, 
such that the maximum between the distance from node1 to that node, 
and from node2 to that node is minimized. 
If there are multiple answers, return the node with the smallest index, 
and if no possible answer exists, return -1.

Note that edges may contain cycles.
 

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        vector<int> a(edges.size(),-1);
        vector<int> b(edges.size(),-1);
        
        int c = 0;
        while(node1 != -1 && a[node1] == -1){
            a[node1] = c++; 
            node1 = edges[node1]; 
        }
        c = 0;
        while(node2 != -1 && b[node2] == -1){
            b[node2] = c++; 
            node2 = edges[node2]; 
        }
        vector<int> all;
        int x= 1e9;
        for(int i = 0; i< edges.size(); i++){
            if(a[i] !=-1 && b[i]!=-1) { 
                if(max(a[i],b[i]) < x) { 
                    all.clear();
                    all.push_back(i);
                    x = max(a[i],b[i]);
                }
                else if(max(a[i],b[i])==x){
                    all.push_back(i);
                }
            }
        }
        if(all.size() == 0) return -1;
        if(all.size()==1) return all[0];
        int ans = 1e9;
        for(int i = 0; i < all.size();i++) ans = min(ans,all[i]); 
        return ans;
    }
};