

/* 

    Solution by Rahul Surana
    
    ***********************************************************


There is a survey that consists of n questions where each question's answer is either 0 (no) or 1 (yes).

The survey was given to m students numbered from 0 to m - 1 and m mentors numbered from 0 to m - 1. 
The answers of the students are represented by a 2D integer array students where students[i] is an integer array that 
contains the answers of the ith student (0-indexed). 
The answers of the mentors are represented by a 2D integer array mentors where mentors[j] is an integer array that contains 
the answers of the jth mentor (0-indexed).

Each student will be assigned to one mentor, and each mentor will have one student assigned to them. 
The compatibility score of a student-mentor pair is the number of answers that are the same for both the student and the mentor.

For example, if the student's answers were [1, 0, 1] and the mentor's answers were [0, 0, 1], 
then their compatibility score is 2 because only the second and the third answers are the same.
You are tasked with finding the optimal student-mentor pairings to maximize the sum of the compatibility scores.

Given students and mentors, return the maximum compatibility score sum that can be achieved.

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:

    int n,m;
    vector<bool> v;

    int score(vector<int> &s, vector<int> &t){
        int a = 0;
        for(int i = 0; i < n; i++) a+= s[i]==t[i];
        return a;
    }

    int df(int i, vector<vector<int>>& students, vector<vector<int>>& mentors){
        if(i>=m ) return 0;
         int ans = 0;
        for(int k = 0; k < m; k++){
            if(!v[k]){
                v[k] = true;
                ans = max(ans, score(students[i], mentors[k]) + df(i+1,students,mentors));
                v[k] = false;
            }
        }
        return ans;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        n = students[0].size();
        m = students.size();
        v.resize(m,false);
        return df(0,students,mentors);
    }
};