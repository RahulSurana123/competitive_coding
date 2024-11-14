

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, 
which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). 
Let x represent the maximum number of products given to any store. You want x to be as small as possible, 
i.e., you want to minimize the maximum number of products that are given to any store.



    ***********************************************************
*/

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        auto z = [&](auto val){
            int x = 0;
            for(auto u: quantities){
                x += u/val;
                if(u%val > 0) x++;
                if(x>n) return false;
            }
            return true;
        };
        int ma = 100001;
        int mi = 1;
        while(mi<ma){
            int mid = (mi+ma)>>1;
            bool f = z(mid);
            if(!f){
                mi = mid+1; 
            }
            else ma = mid;
            // else ma = mid;
        }
        return ma;
    }
};
