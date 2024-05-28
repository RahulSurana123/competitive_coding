

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| 
(i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding 
substring of t with a cost less than or equal to maxCost. 
If there is no substring from s that can be changed to its corresponding substring from t, return 0.


    ***********************************************************
*/


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        int n = s.length();
        vector<int> pre(n,0);

        pre[0] = abs(s[0] - t[0]);
        for(int i = 1; i < n; i++){
            pre[i] = pre[i-1] + abs(s[i]-t[i]);
        }

        int ans = 0, i = -1, j = 0;
        
        while(i<n && j < n){
            if(pre[j]- (i < 0 ? 0 : pre[i]) <= maxCost) { 
                ans = max(ans,j-i); 
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};