

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array target and an integer n.

You have an empty stack with the two following operations:

"Push": pushes an integer to the top of the stack.
"Pop": removes the integer on the top of the stack.
You also have a stream of the integers in the range [1, n].

Use the two stack operations to make the numbers in the stack (from the bottom to the top) equal to target. 
You should follow the following rules:

If the stream of the integers is not empty, pick the next integer from the stream and push it to the top of the stack.
If the stack is not empty, pop the integer at the top of the stack.
If, at any moment, the elements in the stack (from the bottom to the top) are equal to target, 
do not read new integers from the stream and do not do more operations on the stack.
Return the stack operations needed to build target following the mentioned rules. If there are multiple valid answers, return any of them.


    ***********************************************************
*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int  j = 0;
        for(int i = 1; i <= n; i++){
            if(j == target.size()) return ans;
            ans.push_back("Push");
            if(target[j] != i) { 
                ans.push_back("Pop");
                j--;
            } 
            j++;
        }
        return ans;
    }
};