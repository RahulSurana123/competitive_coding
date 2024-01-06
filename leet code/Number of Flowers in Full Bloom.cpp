

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed 2D integer array flowers, 
where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). 
You are also given a 0-indexed integer array people of size n, 
where people[i] is the time that the ith person will arrive to see the flowers.

Return an integer array answer of size n, 
where answer[i] is the number of flowers that are in full bloom when the ith person arrives.


    ***********************************************************
*/


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(),flowers.end());
        vector<vector<int>> st = flowers;
        sort(st.begin(),st.end(), [&](auto a, auto b){ return a[1] < b[1]; });
        int n = people.size();
        vector<int> ans(n,0), idx(n);
        for(int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(),idx.end(),[&](auto a, auto b){ return people[a] < people[b];  });
        int i = 0, j = 0, k = 0;
        while(i < st.size() && k < n){
            while( i < st.size() && st[i][1] < people[idx[k]] ) { i++; }
            while( j < flowers.size() && flowers[j][0] <= people[idx[k]] ) { j++; } 
            ans[idx[k]] = j - i;
            k++;
        } 
        return ans;
    }
};