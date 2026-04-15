
/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.

Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.

Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.


    ***********************************************************
*/


class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int k = 0, n = words.size();
        bool x = true;
        while(x){
            if(words[(startIndex+k)%n] == target) return k;
            if(words[(startIndex-k+n)%n] == target) return k;
            if(k == n) x = false;
            k++;
        }
        return -1;
    }
};
