

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl 
and it returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should work. You just need to ensure 
that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

Implement the Solution class:

Solution() Initializes the object of the system.
String encode(String longUrl) Returns a tiny URL for the given longUrl.
String decode(String shortUrl) Returns the original long URL for the given shortUrl. 
It is guaranteed that the given shortUrl was encoded by the same object.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:

    string l;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // string a = "";
        l = longUrl;
        return "http://tinyurl.com/4e9iAk";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return l;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));