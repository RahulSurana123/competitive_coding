

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of integers nums, there is a sliding window of size k 
which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

Return the max sliding window.



    ***********************************************************
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<int> q;
        multiset<int> s;
        vector<int> ans;
        for(auto x: nums){
            if(q.size() >= k-1){
                int a = q.front();
                if(q.size()>=k){
                q.pop();
                s.erase(s.find(a));
                }
                q.push(x);
                s.insert(x);
                
                // if(s.size()>=0)
                ans.push_back(*(s.rbegin()));
            }
            else{
                q.push(x);
                s.insert(x);
            }
        }
        return ans;
    }
};