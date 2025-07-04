

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.

Now Bob will ask Alice to perform all operations in sequence:

If operations[i] == 0, append a copy of word to itself.
If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
Return the value of the kth character in word after performing all the operations.

Note that the character 'z' can be changed to 'a' in the second type of operation.



    ***********************************************************
*/

    
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long a = k;
        long long z = (1L<<(min((int)operations.size(),60)));
        vector<int> ao;
        while(z>0){ 
            if(a > z) ao.push_back(1);
            else ao.push_back(0);
            if(a>z) a-=z;
            z = z/2;
        }
        std::reverse(ao.begin(),ao.end());
        char ans = 0;
        for(int i = 0; i < ao.size(); i++){
            if(ao[i] == 1 && operations[i] == 1) ans+=1;
            ans%=26;
        }
        return 'a'+(ans);
    }
};