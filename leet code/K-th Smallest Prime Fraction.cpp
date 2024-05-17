

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. 
You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, 
where answer[0] == arr[i] and answer[1] == arr[j].


    ***********************************************************
*/


class Solution {
public:
struct PairCompare {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return (static_cast<double>(a.first) / a.second) > (static_cast<double>(b.first) / b.second);
  }
};
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        // if(k == (n*(n-1))/2) return {arr[n-2],arr.back()};
        vector<int> idx(arr.size(),arr.size()-1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, PairCompare> pq;
        int z = 1;
        pair<int,int> ans = {arr[0],arr.back()};
        while(k--){
            for(int i = 0; i < z; i++) {
                // cout << arr[i] << " " << i <<" "<<arr[idx[i]]<<" "<<idx[i] <<"\n";
                if(idx[i] > i) {
                    pq.push({arr[i],arr[idx[i]]});
                    idx[i]--;
                }
            }
            if(!pq.empty()){
                ans = pq.top();
                pq.pop();
            }
            if(z < arr.size()-1)
            z++;
        }
        return {ans.first,ans.second};
    }
};