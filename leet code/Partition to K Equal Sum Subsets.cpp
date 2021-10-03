




/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums and an integer k, return true 
if it is possible to divide this array into k non-empty subsets whose sums are all equal.



    ***********************************************************
*/



class Solution {
public:
    
    vector<bool> v;
    int ans = 0;
    
    bool df(vector<int>& nums,int i,int sum,int p,int k){
        if(k == 1) return true;
        if(sum>p) { 
            // cout << "exceed undone \n";
            return false; 
        }
        if(sum == p) { 
            // cout << "done \n";
            return df(nums,0,0,p,k-1); 
        }
        for(int j = i; j < nums.size(); j++){
            if(!v[j]){
                v[j] = true;
                // cout << j <<" k "<< k;
                // cout << " s "<<sum+nums[j] <<" -> ";
                if(df(nums,j+1,sum+nums[j],p,k)){
                    
                    return true;
                }   
                v[j] = false;
            }
        }
        // cout << "notdone\n";
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto x: nums){
            sum += x;
        }
        if(k==0 || sum % k) return false;
        int p = sum/k;
        cout << p <<"\n";
        v.resize(nums.size(),false);
        return df(nums,0,0,p,k);;
    }
};