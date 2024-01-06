/* 
   
   Solution by Rahul Surana
    
    ***********************************************************

We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. 
Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.

   
   ***********************************************************

*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        k--;
        if(k<2) return k;
        int i = ceil(log2(k+1));
        bool invert = false;
        while(i>0){
            int x = pow(2,i)-1;
            if(k > x/2 ) { k = x-k; if(i%2) invert^=1; }
            i--;
        }
        return k ^ invert;
    }
};