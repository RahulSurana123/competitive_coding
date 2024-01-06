

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. 
Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in 
all the packages on the conveyor belt being shipped within days days.
 


    ***********************************************************
*/


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        auto x = [&](int a){
            int cap = 0, d = 1;
            for(auto w :weights){
            // cout << a <<" -> \n";
                cap += w;
                if(cap > a){ cap = w; d++; }
            }

            return d;
        };
        int i = 0, j = 0;
        for(int k = 0; k < weights.size(); k++){
            i = max(weights[k],i);
            j+=weights[k];
        }
        while(i < j){
            int m = (i +j)/2;
            int md = x(m);
            if(md > days){
                i = m+1;
            }
            else j=m;
        }
        return i;
    }
};