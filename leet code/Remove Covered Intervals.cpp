
/*


    
    Solution by Rahul Surana
    

    ************************************************************************



Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), 
remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.




    **************************************************************************



*/


#include<bits/stdc++.h>

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int> a, vector<int> b){ 
            if(a[0] == b[0]) return a[1] > b[1]; 
            return a[0] < b[0]; 
        });
        stack<vector<int>> s;
        s.push(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(!(intervals[i][0]>= s.top()[0] && intervals[i][1] <= s.top()[1])) {s.push(intervals[i]);}
        }
        return s.size();
    }
};