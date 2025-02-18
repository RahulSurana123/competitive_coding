
/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.


    ***********************************************************
*/

class Solution {
public:

    unordered_map<int,bool> vv;
    long ans, mvv;

    void df(int i, string pat, long v){
        if(i >= pat.size()) { if(v >= mvv) { ans = min(ans,v); } return; };
        // cout << v << "\n";
        for(int j = 1; j <= 9; j++){
            if(vv[j]) continue;
            if(pat[i] == 'I'){
                if(v%10 < j ) {
                    v*=10;
                    v+=j;
                    vv[j] = true;
                    df(i+1,pat,v);
                    vv[j] = false;
                    v-=j;
                    v/=10;
                }
            }
            else{
                if(v%10 > j) {
                    v*=10;
                    v+=j;
                    vv[j] = true;
                    df(i+1,pat,v);
                    vv[j] = false;
                    v-=j;
                    v/=10;
                }
            }
        }
        return;
    }

    string smallestNumber(string pattern) {
        mvv = 1;
        for(auto x: pattern) mvv*=10;
        ans = 99*mvv;
        mvv/=10;
        for(int i = 1; i <= 9; i++) { vv[i]=true; df(0,pattern,i); vv[i]=false; }
        return to_string(ans);
    }
};
