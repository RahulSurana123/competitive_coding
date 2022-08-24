

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It is guaranteed the answer fits on a 32-bit signed integer.

Input: s = "rabbbit", t = "rabbit"

Output: 3


    ***********************************************************
*/



class Solution {
public:
    
    vector<vector<int>> dp;
    
    int sub(int i, int n, string t,string z,string s){
        cout << z << " ";
        if(t == z) return 1;
        if(i >= n) return 0;
        int count=0;
        int k = 1;
        while( i+k-1 < n && t[z.length()] != s[i+k-1]) k++;
        // if(z == t) { count++; cout << i << " "; }
        if(i+k-1<n) {
        
        count += sub(i+k,n,t,z+s[i+k-1],s);
        count+= sub(i+k,n,t,z,s);
        }
        
        return count;
    }
    
    int subq(string s,string t,int n,int m){
        if(dp[n][m] != -1) return dp[n][m];
        if(m==1 && 1==n) return s[0]==t[0];
        if(m == 0) return 1;
        if(n == 0) return 0;
        if(m>n) return 0;
        // cout << n << " " << m <<" \n";
        int ans = (s[n-1] == t[m-1] ? subq(s,t,n-1,m-1): 0 ) + subq(s,t,n-1,m);
        return dp[n][m] = ans;
    }
    
    int numDistinct(string s, string t) {
        dp.resize(s.size()+1,vector<int>(t.size()+1,-1));
        // int count = 0;
        // for(int i = s.length()-1;i>=0;i++){
        //     if(s[i] == s[s.length()-1]) count++;
        //     v[i] = count;
        // }
        // int ans = sub(0,s.length(),t,"",s);
        int ans = subq(s,t,s.size(),t.size());
        return ans;
    }
};