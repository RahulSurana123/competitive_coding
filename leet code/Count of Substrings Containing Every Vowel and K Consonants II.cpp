
/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.



    ***********************************************************
*/

class Solution {
public:
    bool is_v(char a){
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
    }

    bool all_set(int* f){
        return f[0] > 0 && f[4] > 0 && f[8] > 0 && f[14] > 0 && f[20] > 0;
    }

    long long countOfSubstrings(string word, int k) {
        long long ans = 0;
        int i = 0, j = 0, v_c = 0, k_c = 0, ei = 0;
        int f[26] = {0};
        while(j < word.length()){
            if(is_v(word[j])){ v_c++; f[word[j]-'a']++; }
            else k_c++;
            while(k_c>k){
                char lc = word[i++];
                if(is_v(lc)){
                    v_c--;
                    f[lc-'a']--;
                }
                else k_c--;
                ei = 0;
            }
            while(all_set(f) && k_c == k && i < j && is_v(word[i]) && f[word[i]-'a']>1){
                ei++;
                f[word[i++]-'a']--;
            }
            if(k_c == k && all_set(f)) ans += 1+ei;
            j++;
            // cout << ans <<" " <<i <<" "<< j <<" "<<k_c<<"\n";
        }
        return ans;
    }
};
