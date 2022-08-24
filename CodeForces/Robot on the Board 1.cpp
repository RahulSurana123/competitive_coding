

/* 

    Solution by Rahul Surana
    

    ***********************************************************


The robot is located on a checkered rectangular board of size n×m (n rows, m columns). 
The rows in the board are numbered from 1 to n from top to bottom, and the columns — from 1 to m from left to right.

The robot is able to move from the current cell to one of the four cells adjacent by side.

The sequence of commands s executed by the robot is given. 
Each command is denoted by one of the symbols 'L', 'R', 'D' or 'U', and triggers the movement to left, right, down or up, respectively.

The robot can start its movement in any cell. The robot executes the commands starting from the first one, 
strictly in the order in which they are listed in s. 
If the robot moves beyond the edge of the board, it falls and breaks. 
A command that causes the robot to break is not considered successfully executed.

The robot's task is to execute as many commands as possible without falling off the board. 
For example, on board 3×3, if the robot starts a sequence of actions s="RRDLUU" 
("right", "right", "down", "left", "up", "up") from the central cell, the robot will perform one command, 
then the next command will force him to cross the edge. 
If the robot starts moving from the cell (2,1) (second row, first column) then all commands will be executed successfully 
and the robot will stop at the cell (1,2) (first row, second column).

The robot starts from cell (2,1) (second row, first column). It moves right, right, down, left, up, and up. 
In this case it ends in the cell (1,2) (first row, second column).
Determine the cell from which the robot should start its movement in order to execute as many commands as possible.

Input
The first line contains an integer t (1≤t≤104) — the number of test cases.

The next 2t lines contain descriptions of the test cases.

In the description of each test case, the first line contains two integers n and m (1≤n,m≤106) — the height and width of the field that the robot is located on. 
The second line of the description is a string s consisting solely of characters 'L', 'R', 'D' and 'U' — the sequence of commands the robot executes. 
The string has a length from 1 to 106 commands.

It is guaranteed that the total length of s over all test cases does not exceed 106.

Output
Print t lines, each of which contains the answer to the corresponding test case. The answer to the test case are two integers r (1≤r≤n) and c (1≤c≤m), separated by a space — the coordinates of the cell (row number and column number) from which the robot should start moving to perform as many commands as possible.

If there are several such cells, you may output any of them.

        

    ***********************************************************
*/



#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >>t;
    int z = t;
    while(t--){
        // cout << "t : " << z-t << "\n";
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        int x = 0,y = 0;
        int mu=0,ml=0,md=0,mr=0;
        for(int i = 0; i  < s.length();i++){
            // cout << x << " " << y <<" "<< s[i] <<"\n";    
            if(s[i] == 'U'){
                y-=1;
                if(y < -n+1) break;
                if(md-y>n-1) break;
                if(mu > y) mu = y;
            }else if(s[i] == 'D'){
                y+=1;
                if(y > n+mu-1) break;
                if(y-mu>n-1) break;
                if(md<y) md = y;
            }else if(s[i] == 'L'){
                x-=1;
                if(x < -m+1) break;
                if(mr-x > m-1) break;
                if(ml > x) ml = x;
            }else if(s[i] == 'R'){
                x+=1;
                if(x>m+ml) break;
                if(x-ml>m-1) break;
                if(mr<x) mr = x;
            }
        }
        cout << abs(mu)+1 << " " << abs(ml)+1 <<"\n";
        // cout <<"\n";
    }
    
    return 0;
}