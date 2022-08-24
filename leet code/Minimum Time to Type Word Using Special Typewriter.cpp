

/* 
    Solution by Rahul Surana
    
    ***********************************************************

There is a special typewriter with lowercase English letters 'a' to 'z' arranged in a circle with a pointer. A character can only be typed if the pointer is pointing to that character. The pointer is initially pointing to the character 'a'.


Each second, you may perform one of the following operations:

Move the pointer one character counterclockwise or clockwise.
Type the character the pointer is currently on.
Given a string word, return the minimum number of seconds to type out the characters in word.


    ***********************************************************
*/



class Solution {
public:
    int minTimeToType(string word) {
        char last = 'a';
        int count = 0;
        for(int i = 0; i < word.length(); i++){
            // if(word[i] > last) 
            count += min(abs('z'-last+1 +word[i]-'a')%26,abs( 'z'-word[i] + 1 + last -'a')%26);
            // else count+= min(abs(last - word[i]),abs(last - 'z' + word[i] -'a'));
            // count += min(abs(word[i] - last), abs(word[i] - (last-26))) ;
            
            cout << abs(last - word[i])%26 <<" " << abs('z' - word[i] + 1 + last - 'a')%26 << " ";
            last = word[i];
        }
        cout <<"\n";
        return count+ word.length();
    }
};