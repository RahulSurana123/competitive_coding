



/* 

    Solution by Rahul Surana
    
    ***********************************************************


Recursive powers

You are given two numbers Y and Z, let X0 be the exact solution of the equation  containing Y number of X. 

Task

Calculate the value of X1 such that | X1 - X0 | <= 10-7.

Note: You should find the value of X1 and output the value of  rounded the nearest integer.

Example

Assumptions

Y = 3
Z = 16
Approach

X0 = 2 is the exact solution of the equation . Therefore, you can choose X1 = 2.
Hence, the output is 2000.

Function description

Complete the findX function provided in the editor. This function takes the following 2 parameters and returns the required value of X:

Y: Represents the number of times X appears in the equation
Z: Represents the value Z given in the equation
Input format

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

The first line contains a single integer T denoting the number of test cases. T also specifies the number of times you have to run the findX function on a different set of inputs.
For each test case:
The first line contains 2 space-separated integers denoting the values of Y and Z.
Output format

For each test case, print only a single integer in a single line denoting the value  rounded the nearest integer




    ***********************************************************
*/




#include<bits/stdc++.h>
using namespace std;


long double findX (long double Y,long double Z) {
    cout << setprecision(4);
    long double s = 1,e = 10007;
    if(Z <= 1.000001) return Z;
    // if(Z > ) 
    // cout << "yo"<<"\n";
    while(s < e){
        long double m = s + ((e-s)/2);
        long double x = m;
        for(int i = 0; i < Y-1; i++){
            x = pow(m,x);
        }
        // if((m-1.669)<0.1)
        // cout << m <<" " << x<<"\n";
        if( Z-x < -0.000001) e = m;
        else if(abs(Z-x) > 0.000001) s = m;
        else return m;
    }
    return e;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        long double Y;
        cin >> Y;
        long double Z;
        cin >> Z;

        long double out_;
        out_ = findX(Y, Z)*1000;
        cout << out_;
        cout << "\n";
    }
}