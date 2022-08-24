

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of n distinct elements. 
Find the minimum number of swaps required to sort the array in strictly increasing order.



    ***********************************************************
*/


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
    int minSwaps(vector<int>&nums)
    {
        vector<int> t(nums.begin(),nums.end());
        sort(t.begin(),t.end());
        unordered_map<int,int> m;
        for(int i = 0; i < t.size(); i++) m[nums[i]] = i;
        int ans = 0;
        for(int i = 0; i < t.size(); i++){
            if(nums[i] == t[i]) continue;
            if(nums[i] != t[i]) {
                ans++;
                int x = nums[i];
                nums[i] = nums[m[t[i]]];
                nums[m[t[i]]] = x;
                m[x] = m[t[i]];
                m[t[i]] = i;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans <<"\n";
    }
    return 0;
}  // } Driver Code Ends