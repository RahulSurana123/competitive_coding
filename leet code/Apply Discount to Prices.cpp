


/* 
    Solution by Rahul Surana
    
    ***********************************************************

A sentence is a string of single-space separated words where each word can contain digits, lowercase letters, and the dollar sign '$'. A word represents a price if it is a sequence of digits preceded by a dollar sign.

For example, "$100", "$23", and "$6" represent prices while "100", "$", and "$1e5" do not.
You are given a string sentence representing a sentence and an integer discount. For each word representing a price, apply a discount of discount% on the price and update the word in the sentence. All updated prices should be represented with exactly two decimal places.

Return a string representing the modified sentence.

Note that all prices will contain at most 10 digits.

    ***********************************************************
*/

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int i = 0, n = sentence.size();
        std::ostringstream ans;
        while(i < n){
            if(sentence[i] =='$') {
                if(i>0 && sentence[i-1] != ' ') {
                    ans << sentence[i++];
                    continue;
                }
                ans << sentence[i++];
                if(i==n) break;
                string z;
                while( i < n && sentence[i] >= '0' && sentence[i] <='9') {
                    z += sentence[i++];
                }
                // cout << z <<" ";
                if( (z != "" && i<n&&sentence[i] == ' ') || i == n) {
                    double v = stol(z)*(1.0-((discount*1.0)/100));
                    ans << std::format("{:.2f}",v);
                }else{
                    ans <<z;
                }
            }
            else ans << sentence[i++];
        }
        return ans.str();
    }
};
