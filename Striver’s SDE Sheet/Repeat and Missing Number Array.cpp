

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.



    ***********************************************************
*/


#include <bits/stdc++.h>


vector<int> Solution::repeatedNumber(const vector<int> &A) {

    long long a = 0, b = 0,temp;
    for(int i = 0; i < A.size();i++) {
        temp = A[i]; 
        a += temp;
        b += (temp * temp);
        a -= (i+1);
        b -= ((long long)(i+1) *(long long)(i+1));
    }
    b/=a;
    int e = (int)((b + a) / 2);
    int f = b - e;
    // }cout << A.size()<<" ";
    
    
    return {e,f};
}
