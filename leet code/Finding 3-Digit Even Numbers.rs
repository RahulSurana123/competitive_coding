
/*

You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.

*/ 

use std::collections::HashSet;
impl Solution {

    pub fn en3d(a:i32,b:i32,c:i32) -> Vec<i32> {
        let mut v = Vec::new();
        if c % 2 == 0 {
            if a != 0 { 
                v.push(a*100+b*10+c); 
            }
            if b != 0 { 
                v.push(b*100+a*10+c);
            }    
        }
        if b % 2 == 0 {
            if a != 0 {
                v.push(a*100+c*10+b);
            }
            if c != 0 { 
                v.push(c*100+a*10+b);
            }    
        }
        if a % 2 == 0 {
            if c != 0 { 
                v.push(c*100+b*10+a);
            }
            if b != 0 { 
                v.push(b*100+c*10+a);    
            }
        }
        v
    }

    pub fn find_even_numbers(digits: Vec<i32>) -> Vec<i32> {
        let mut s:HashSet<i32> = HashSet::new();
        for i in 0..digits.len(){
            for j in i+1..digits.len(){
                for k in j+1..digits.len(){
                    let x = Solution::en3d(digits[i],digits[j],digits[k]);
                    for l in x {
                        s.insert(l);
                    }

                }
            }
        }
        let mut s = Vec::<i32>::from_iter(s);
        s.sort();
        return s;
    }
}