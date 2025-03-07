
/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. 
If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. 
If no such numbers exist, return [-1, -1].



    ***********************************************************
*/

class Solution {
public:
    static constexpr auto fast_io =  [](){  std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL); };
    vector<int> closestPrimes(int left, int right) {
        vector<bool> m(right+1,false);
        m[1] = true;
        for(long i = 2; i <= right; i++){
            if(m[i]) continue;
            m[i] = false;
            for(long j = i*i; j <= right; j+=i){
                m[j] = true;
            }
        }
        int mi = 1e7;
        int x = -1, y1 = -1, y2 = -1;
        for(int i = left; i <= right; i++){
            if(m[i]) continue;
            
            if( i-x +1 < mi) { y1 = x; y2 = i; mi = min(i-x+1,mi);  }
            x = i;
            
            // cout << i <<" "<<x<<" "<< y2 <<" "<<y1<<"\n";
        }
        return {y1,y1 == -1?-1:y2};
    }
};
