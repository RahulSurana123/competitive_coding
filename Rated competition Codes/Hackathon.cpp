

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Coding Ninjas is organizing a 10-day long hackathon, in which students from all over the world are participating. In order to accommodate such a massive amount of students, they have rented N apartments, numbered from 1 to N. Each apartment consists of a[i] rooms, and the rooms in the i-th apartment are numbered from 1 to a[i].
In order to combat cheating, mobile phones are strictly prohibited in the area and to welcome the winners of the last hackathon, letters are being sent out to them. However, the managers forgot to add the specific apartment number and the room number on the letters. Instead, only the room number is mentioned. Assume that the rooms are numbered from 1 to a1 + a2 + a3 +....+ aN.
For each of the M letters, determine the particular apartment and the room number in the apartment where the letter must be delivered.



    ***********************************************************
*/



#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n,m;
    cin >> n>>m;
    long ar[n],b[m];
    for(int i = 0; i < n; i++) cin>> ar[i];
    for(int i = 0; i < m; i++) cin>> b[i];
    for(int i = 0; i < m; i++){
        long k = b[i];
        int c = 0;
        while(k > ar[c]) { k-=ar[c]; c++; }
        cout << c+1 << " "<< k <<"\n";
    }
    return 0;
}