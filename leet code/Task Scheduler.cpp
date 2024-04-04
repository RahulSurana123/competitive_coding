

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. 
Each cycle or interval allows the completion of one task. 
Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.


    ***********************************************************
*/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mm;
        for(char x: tasks) mm[x]++;
        int s1 = 0, s = 0, c = 1;
        for(auto [a,b]: mm){
            if(s1 < b){
                s1 = b; c = 1;
            }
            else if(s1 == b) c++;
            s += b;
        }
        return max(s1+c-1+((s1-1)*n),s);
    }
};