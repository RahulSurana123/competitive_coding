

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array data representing the data, return whether it is a valid UTF-8 encoding (i.e. it translates to a sequence of valid UTF-8 encoded characters).

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For a 1-byte character, the first bit is a 0, followed by its Unicode code.
For an n-bytes character, the first n bits are all one's, the n + 1 bit is 0, followed by n - 1 bytes with the most significant 2 bits being 10.
This is how the UTF-8 encoding would work:

     Number of Bytes   |        UTF-8 Octet Sequence
                       |              (binary)
   --------------------+-----------------------------------------
            1          |   0xxxxxxx
            2          |   110xxxxx 10xxxxxx
            3          |   1110xxxx 10xxxxxx 10xxxxxx
            4          |   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
x denotes a bit in the binary form of a byte that may be either 0 or 1.

Note: The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for(int i = 0; i < data.size(); i++){
            int x = data[i];
            if(x>=240 && x < 248){
                if(i+3>data.size()-1 || data[i+1]<128 ||data[i+1]>=192||  data[i+2]<128||data[i+2]>=192 || data[i+3]<128||data[i+3]>=192){
                    return false;
                }
                i+=3;
            }
            else if(x>=224 && x < 240){
                if(i+2>data.size()-1 || data[i+1]<128||data[i+1]>=192 ||  data[i+2]<128||data[i+2]>=192){
                    return false;
                }
                i+=2;
            }
            else if(x>=192 && x < 224){
                if(i+1>data.size()-1 || data[i+1]<128||data[i+1]>=192){
                    return false;
                }
                i+=1;
            }
            else if(x > 127){
                return false;
            }
        }
        return true;
    }
};