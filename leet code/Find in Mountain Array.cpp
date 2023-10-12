

/* 
    Solution by Rahul Surana
    
    ***********************************************************

(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. 
If such an index does not exist, return -1.

You cannot access the mountain array directly. 
You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. 
Also, any solutions that attempt to circumvent the judge will result in disqualification.


    ***********************************************************
*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int df(int s, int e,  MountainArray &mA, int &t, bool isL){
        if(s>e) return -1;
        int u = mA.get(s);
        if( s == e ) return ( u == t ? s: -1);
        int m = (s+(e-s)/2);
        int v = mA.get(m);
        // cout << s <<" "<<m<<" "<<e <<" "<< v<<"\n";
        if(v == t) return m;
        else if(isL && v < t) return df(m+1,e,mA,t,isL);
        else if(isL) return df(s,m-1,mA,t,isL);
        else if(!isL && v < t) return df(s,m-1,mA,t,isL);
        return df(m+1,e,mA,t,isL);
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int s = 0, e = n-1, m;
        while(s<e){
            m = s+(e-s)/2;
            int v = mountainArr.get(m);
            
            if(v < mountainArr.get(m+1)) s = m+1;
            else e = m;
        }
        // cout << s <<"\n";
        int a = df(0,s,mountainArr,target, true);
        int b = df(s+1,n-1,mountainArr,target, false);
        if(a != -1) return a;
        return b; 
    }
};