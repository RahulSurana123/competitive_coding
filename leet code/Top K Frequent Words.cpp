

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. 
Sort the words with the same frequency by their lexicographical order.
 



    ***********************************************************
*/


class Solution {
public:
    
   
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> s;
         unordered_map<string,int> m;
        for(auto z: words){
            if(m[z] == 0){
                s.push_back(z);
                m[z]++;
                
            }
            else{
                m[z]++;
            }
        }
        sort(s.begin(),s.end(),[&](auto a, auto b){ if(m[a]==m[b]) return a<b; return m[a]>m[b]; });
        return  vector<string>(s.begin(),(s.begin()+k));
    }
};