

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.



    ***********************************************************
*/


class Solution {
public:
    string reorganizeString(string s) {
        vector<int> f(26,0);
        for(auto x: s){
            f[x-'a']++;
            if(f[x-'a'] > (s.length()+1)/2 ) return "";
        }
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26; i++){
            if(f[i] > 0) pq.push({f[i], i+'a'});
        }
        string ans = "";
        while(!pq.empty()){
            auto a = pq.top();
            pq.pop();
            if(pq.empty()) return (ans+a.second);
            auto b = pq.top();
            pq.pop();
            ans += a.second;
            ans += b.second;
            if(a.first > 1)
            pq.push({a.first-1,a.second});
            if(b.first > 1) 
            pq.push({b.first-1,b.second});
        }
        return ans;
    }
};