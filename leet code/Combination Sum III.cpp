
/* 

    Solution by Rahul Surana

    ***********************************************************

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. 
The list must not contain the same combination twice, and the combinations may be returned in any order.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    set<vector<int>> ans;
    map<set<int>,bool> m;
    
    void df(int g, set<int> x, int s, int k, int n){
        if(s>n || x.size() >k || m[x]) return;
        m[x] = true;
        cout << s <<" -> ";
        for(auto a: x) cout << a <<" ";
        cout <<"\n";
        if(s == n && x.size() == k){
            ans.insert(vector<int>(x.begin(),x.end()));
            return;
        }
        for(int i = g; i <= 9;i++){
            if(!x.count(i)){
                set<int> z(x.begin(),x.end());
                z.insert(i);
                df(i+1,z,s+i,k,n);
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n > 9*5 || n < (k*(k+1)/2)) return vector<vector<int>>();
        set<int> x;
        df(1,x,0,k,n);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};