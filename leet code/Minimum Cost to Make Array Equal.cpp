

/* 

    Solution by Rahul Surana
    
    ***********************************************************

You are given two 0-indexed arrays nums and cost consisting each of n positive integers.

You can do the following operation any number of times:

Increase or decrease any element of the array nums by 1.
The cost of doing one operation on the ith element is cost[i].

Return the minimum total cost such that all the elements of the array nums become equal.


    ***********************************************************
*/


class Solution {
public:

void pairsort(vector<int> &a, vector<int> &b)
{
    pair<int, int> pairt[a.size()];
    for (int i = 0; i < a.size(); i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }
    sort(pairt, pairt + a.size());
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        pairsort(nums,cost);
        vector<long> ps(n,0);
        ps[0] = cost[0];
        for(int i = 1; i < n; i++){
            ps[i] = ps[i-1] + cost[i];
        }
        
        long long t = 0;
        for(int i = 1; i < n; i++){
            t += (nums[i] - nums[0]) * (long)cost[i];
        }
        long long ans = t;
        for(int i = 1; i < n; i++){
            int g = nums[i] - nums[i-1];
            t += ps[i-1]*g;
            t -= (ps[n-1]-ps[i-1])*g; 
            ans = min(ans, t);
        }
        return ans;
    }
};