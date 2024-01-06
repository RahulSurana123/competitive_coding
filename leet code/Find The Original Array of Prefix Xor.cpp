/* 
   
   Solution by Rahul Surana
    
    ***********************************************************

You are given an integer array pref of size n. Find and return the array arr of size n that satisfies:

pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
Note that ^ denotes the bitwise-xor operation.

It can be proven that the answer is unique.

 

   
   ***********************************************************

*/

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int x = pref[0],z;
        for(int i = 1; i < pref.size(); i++){
            z = pref[i];
            pref[i] = x ^ z;
            x = z;
        }
        return pref;
    }
};