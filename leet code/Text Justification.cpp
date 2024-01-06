

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an array of strings words and a width maxWidth, format the text such that each line has 
exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, 
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.


    ***********************************************************
*/


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<int> es;
        vector<int> wc(1,0);
        int id = 0, l = 0;
        for(int i = 0 ; i < n; i++){
            
            if(words[i].length() + l + wc[id] > maxWidth) { es.push_back(maxWidth -l); wc.push_back(0); l = 0; id++; }
            l += words[i].length();
            wc[id]++;
        }
        if(es.size() <= id) es.push_back(maxWidth - l);
        if(wc.size() <= id) wc.push_back(1);
        vector<string> ans;
        int ind = 0;
        for(int i = 0; i <= id; i++){
            string a = "";
            int j = 0;
            int k = wc[i]==1? es[i] : es[i] % (wc[i]-1);
            int esl = wc[i] == 1? es[i] : es[i] / (wc[i]-1);
            while(j < wc[i]) { 
                a += words[j+ind]; 
                j++;  
                if((j != wc[i] && i != id && esl != 0))
                a += string(esl,' ');
                else if(i==id) k = 1;
                if(k>0) {
                    a += string(1,' '); 
                    k--; 
                }
            }
            if(wc.size() >= i)
            ind += wc[i];
            if(a.length() < maxWidth){
                a += string(maxWidth-a.length(),' ');
            }
            ans.push_back(a.substr(0,maxWidth)); 
        }
        return ans;
    }
};