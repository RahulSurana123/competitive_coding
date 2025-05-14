
/*

You are given a string s and an integer t, representing the number of transformations to perform. 
In one transformation, every character in s is replaced according to the following rules:

If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. 
For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

*/ 

use std::collections::VecDeque;
const MOD: i32 = 10_i32.pow(9) + 7;
impl Solution {
    pub fn length_after_transformations(s: String, t: i32) -> i32 {
        let mut f = VecDeque::from([0;26]);
        for c in s.into_bytes() {
            f[(c - b'a') as usize] += 1;
        }
        for _ in 0..t {
            let z = f.pop_back().unwrap();
            f[0] = (f[0] + z) %MOD;
            f.push_front(z);
        }
        f.into_iter().reduce(|a,b| (a + b) % MOD).unwrap()
    }
}

