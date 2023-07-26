

/* 

    Solution by Rahul Surana
    
    ***********************************************************

You are given a floating-point number hour, representing the amount of time 
you have to reach the office. 
To commute to the office, you must take n trains in sequential order. 
You are also given an integer array dist of length n, where dist[i] describes 
the distance (in kilometers) of the ith train ride.

Each train can only depart at an integer hour, so you may need to wait in between each train ride.

For example, if the 1st train ride takes 1.5 hours, you must wait for an additional 0.5 hours 
before you can depart on the 2nd train ride at the 2 hour mark.
Return the minimum positive integer speed (in kilometers per hour) that all 
the trains must travel at for you to reach the office on time, or -1 if it is impossible to be on time.

Tests are generated such that the answer will not exceed 107 and 
hour will have at most two digits after the decimal point.

    ***********************************************************
*/

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s = 0, e = 10000001;
        auto f = [&](int &m ){
            double r=0;
            for(int i = 0; i < dist.size(); i++){
                if( i == dist.size()-1) r += (double)dist[i]/m;
                else r += ceil((double)dist[i]/m);
            }
            return r;
        };
        int ans = 0;
        while(s<=e){
            int m = (s+e)>>1;
            if(f(m) > hour){s = m+1; }
            else { e = m-1; ans = m;}
        }
        return ans? ans:-1;
    }
};