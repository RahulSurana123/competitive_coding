

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.



    ***********************************************************
*/

class Solution {
public:

    vector<vector<int>> ans;

    void df(int i,int n, int k, vector<int> &p){
        if(k==0) {ans.push_back(p); return;}
        if(i>n) return;
        p.push_back(i);
        df(i+1,n,k-1,p);
        p.pop_back();
        df(i+1,n,k,p);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> a;
        df(1,n,k,a);
        return ans;
    }
};