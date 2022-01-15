

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    
    map<int,vector<int>> m;
    // map<int,int> v;
    
    int minJumps(vector<int>& arr) {
        // vector<int> dp(arr.size(),-1);
        if(arr.size()==1) return 0;
        queue<int> q;
        q.push(0);
        // dp[0] = 0;
        int step = 0;
        for(int i = 0 ; i < arr.size(); i++){
            m[arr[i]].push_back(i);
        }
        
        while(!q.empty()){
            int size = q.size();
            
            for(int _i = 0 ; _i < size; _i++) {
                auto x = q.front();
                // cout << x.first <<" "<< x.second <<"\n";
                q.pop();
                // if(x == arr.size()-1) return step;
                if(x < 0 || x > arr.size()-1) continue;
                if(x+1 < arr.size() && m.find(arr[x+1]) != m.end()) {
                    // cout << x+1 <<" "<< step <<"\n";
                    q.push(x+1);
                    if(x+1 == arr.size()-1) return step+1;
                    // dp[x.first + 1] = x.second+1;
                }
                if(x-1 > -1 && m.find(arr[x-1]) != m.end()){
                    // cout << x <<" "<< step <<"\n";
                    q.push(x-1);
                    if(x-1 == arr.size()-1) return step+1;
                    // dp[x.first-1] = x.second+1;
                }
                for(auto a: m[arr[x]]){
                    if(x != a){
                        // cout << a <<" "<< step <<"\n";
                        q.push(a);
                        if(arr.size()-1 == a) return step+1;
                        // dp[a] = x.second+1;
                    }
                }
                m.erase(arr[x]);
            }
            step++;
        }
        return step;
    }
};