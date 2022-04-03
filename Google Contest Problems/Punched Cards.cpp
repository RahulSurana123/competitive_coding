
/* 

    Solution by Rahul Surana

    ***********************************************************

Problem
A secret team of programmers is plotting to disrupt the programming language landscape and bring punched cards 
back by introducing a new language called Punched Card Python that lets people code in Python using punched cards! Like good disrupters, 
they are going to launch a viral campaign to promote their new language before even having the design for a prototype. 
For the campaign, they want to draw punched cards of different sizes in ASCII art.

Example Punched Card.

The ASCII art of a punched card they want to draw is similar to an R×C matrix without the top-left cell. 
That means, it has (R⋅C)−1 cells in total. Each cell is drawn in ASCII art as a period (.) 
surrounded by dashes (-) above and below, pipes (|) to the left and right, and plus signs (+) for each corner. 
Adjacent cells share the common characters in the border. 
Periods (.) are used to align the cells in the top row.

For example, the following is a punched card with R=3 rows and C=4 columns:

..+-+-+-+
..|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
|.|.|.|.|
+-+-+-+-+
There are more examples with other sizes in the samples below. Given the integers R and C describing the size of a punched card, print the ASCII art drawing of it as described above.

Input
The first line of the input gives the number of test cases, T. T lines follow, each describing a different test case with two integers R and C: the number of rows and columns of the punched card that must be drawn.

Output
For each test case, output one line containing Case #x:, where x is the test case number (starting from 1). Then, output (2⋅R)+1 additional lines with the ASCII art drawing of a punched card with R rows and C columns.


    ***********************************************************
*/



#include <bits/stdc++.h>
#define ll          long long
#define vl          vector<ll>
#define vi          vector<int>
#define pi          pair<int,int>
#define pl          pair<ll,ll>
#define all(a)      a.begin(),a.end()
#define mem(a,x)    memset(a,x,sizeof(a))
#define pb          push_back
#define mp          make_pair
#define F           first
#define S           second
#define trace(x)    cerr<<#x<<" : "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" : "<<x<<" | "<<#y<<" : "<<y<<" | "<<#z<<" : "<<z<<endl;
#define fast_io 	std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
 
using namespace std;

int MOD=1e9+7;


int main()
{
	fast_io;
    int t,w = 1;
    cin >> t;
    while(t >= (w)){

        ll n,m;
        cin >> n >> m;  
         // cout << a << " " << b <<"\n";
        cout << "Case #" << w << ": " << "\n";
        for(int i = 0; i < 2*n+1; i++){
            for(int j = 0; j < 2*m+1; j++){
                if(i<2 && j<2){
                    cout << ".";
                }
                else if(i%2 == 0 && j %2 == 0){
                    cout <<"+";
                }
                else if(i%2 == 0 && j %2 == 1){
                    cout <<"-";
                }
                else if (i%2 == 1 && j %2 == 0){
                    cout << "|";
                }
                else{
                    cout << ".";   
                }
            }
            cout <<"\n";
        }
        w++;
    }
        
}