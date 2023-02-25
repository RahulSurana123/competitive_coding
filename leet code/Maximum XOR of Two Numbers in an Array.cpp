

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    
    struct TreeNode {
        int val;
        TreeNode* bit[2];
        
        TreeNode(){
            this->bit[0] = NULL;
            this->bit[1] = NULL;
        }
        
        void add(int number){
            TreeNode* temp = this;
            for(int i = 31; i>=0; i--){
                int x = ((number&(1<<i)) > 0);
                // cout << x<<" ";
                if(temp->bit[x] == NULL) {
                    temp->bit[x] = new TreeNode();
                    temp = temp->bit[x];
                }
                else temp = temp->bit[x];
            }
        }
        int get(int number){
            TreeNode* temp = this;
            int ans = 0;
            for(int i = 31; i >=0; i--){
                int x = ((number&(1<<i)) > 0);
                // cout << x <<" ";
                if(temp->bit[1-x] != NULL) {
                    ans += (1<<i);
                    temp = temp->bit[1-x];
                    
                }
                else {
                    // cout <<"yo ";
                    // ans -= (1<<i);
                    temp = temp->bit[x];
                }
                // cout << number <<" " << ans <<"\n";
            }
            
            return ans;
        }
    };
    
    int findMaximumXOR(vector<int>& nums) {
        TreeNode* root = new TreeNode();
        // map<int, set<int>> map;
        for(int i = 0; i < nums.size(); i++){
            root->add(nums[i]);
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans = max(root->get(nums[i]),ans);
        }
        return ans;
    }
};