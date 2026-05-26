

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given two arrays with positive integers arr1 and arr2.

A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.

A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have common prefixes 565 and 5655 while 1223 and 43456 do not have a common prefix.

You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.

Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.


    ***********************************************************
*/

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for(auto x: arr1){
            while(x > 0){
                s.insert(x);
                // cout << x <<" ";
                x/=10;
            }
        }
        // cout <<"\n";
        int ans = 0;
        for(auto x: arr2){
            while(x > 0){
                if(s.count(x)) {
                    // cout << x <<" ";
                    int si = to_string(x).length();
                    ans = max(ans,si);
                    break;
                }
                // s.insert(x);
                x/=10;
            }
        }
        return ans;
    }
};
