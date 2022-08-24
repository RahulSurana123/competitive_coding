



/* 
    Solution by Rahul Surana
    
    ***********************************************************

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. 
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].


    ***********************************************************
*/



class Solution {
public:
//     typedef struct Tree{
//         Tree* right;
//         Tree* left;
//         int val;
//         Tree(int a){
//             val = a;
//             right = NULL;
//             left = NULL;
//         }
//     }Tree;
    
//     Tree* getBST(vector<int> arr,int size){
//         Tree* root = NULL;
//         for(int i=0;i<size;i++)
//             insert(&root,arr[i]);
//         return root;
//     }
    
//     void insert(Tree** root, int v){
//         if(*root == NULL){
//             *root = new Tree(v);
//         }
//         else if( (*root)->val > v){
//             insert(&((*root)->left),v);
//         }
//         else if((*root)->val < v){
//             insert(&((*root)->right),v);
//         }
//     }
    
//     void f(int n,int k,vector<int> nums){
        
        
        // if(k==n-1) return 0;
        // if(dp[k] != -1) return dp[k];
        // int ans = 0;
        // // ans = max(ans,__builtin_popcount(x));
        // for(int i = k+1 ; i < n; i++){
        //     if(nums[k] < nums[i] ){
        //         // cout << nums[k] <<" "<< nums[i]<<" "<< ans << " -> ";
        //         // cout << k <<" ";
        //         dp[i] = f(n,i,nums);
        //         // cout <<k<<" <- "<<i <<" ";
        //         // cout << nums[k] <<" "<< nums[i]<<" "<< ans << " -> ";
        //         ans = max(ans,dp[i]+1);
        //         // cout << bitset<11>(m) << " ";
        //     }
        // }
        
        // return dp[k] = ans;
    // }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> a = {nums[0]};
        int len = 1;
        for(int i = 1; i < n; i++){
            if(a[len-1] < nums[i]){
                a.push_back(nums[i]);
                len++;
            }
            else{
                int x = lower_bound(a.begin(),a.end(),nums[i]) - a.begin();
                a[x] = nums[i];
            }
        }
        return len;
    }
};