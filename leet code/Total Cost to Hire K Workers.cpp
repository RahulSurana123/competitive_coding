

/* 

    Solution by Rahul Surana
    
    ***********************************************************

You are given a 0-indexed integer array costs where costs[i] is the cost of hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k workers according to the following rules:

You will run k sessions and hire exactly one worker in each session.

In each hiring session, choose the worker with the lowest cost from either the first candidates workers or the last candidates workers. 
Break the tie by the smallest index.
For example, if costs = [3,2,7,7,1,2] and candidates = 2, then in the first hiring session, 
we will choose the 4th worker because they have the lowest cost [3,2,7,7,1,2].
In the second hiring session, we will choose 1st worker because they have the same lowest cost as 4th worker but they have the smallest index [3,2,7,7,2]. 
Please note that the indexing may be changed in the process.
If there are fewer than candidates workers remaining, choose the worker with the lowest cost among them. Break the tie by the smallest index.
A worker can only be chosen once.

Return the total cost to hire exactly k workers.


    ***********************************************************
*/


class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
         int n = costs.size();
        if (candidates * 2 + k > n) {
            nth_element(begin(costs), begin(costs) + k, end(costs));
            return accumulate(begin(costs), begin(costs) + k, 0ll);
        }
        priority_queue<int,vector<int>, greater<int>> 
                                            pqf(costs.begin(),costs.begin()+candidates),
                                            pqb(costs.end()- candidates,costs.end());
       
        long ans = 0,i = candidates,j = n-candidates-1;
        while(k--){
            int x;
            if(pqf.top() <= pqb.top()){
                x = pqf.top();
                pqf.pop();
                if(i <= j) pqf.push(costs[i++]);
            }
            else{
                x = pqb.top();
                pqb.pop();
                if(i <= j) pqb.push(costs[j--]);
            }
            ans+=x;
        }
        return ans;
    }
};