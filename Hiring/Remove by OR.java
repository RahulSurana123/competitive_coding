/* 

    Solution by Rahul Surana

    ***********************************************************

Remove by OR

You are given an array of N integers. All the integers will be of the form of 10000...... (when converted to binary) i.e starting with bit 1, followed by any number of zeros (possibly 0). Perform the operation as follows:



Choose any subsequence of the current array.

Chosen subsequence must not contain any duplicates.

If chosen subsequence is 

 then  ( 

 ) where X is any number of the form of 1010101..... (when converted to binary) i.e starting with bit 1, followed by alternate 0's and 1's  ( 1, 10, 101, 1010 are valid values for X while 0, 01, 110, 010 are invalid).

Delete this subsequence from the array (array gets updated)

Here, | represents OR operation.



Task



Check if it is possible to make the array empty after some number of operations. If possible, print YES else print NO.



Example 



Assumptions



N = 4

A = [2, 2, 1, 8]

Approach



Choose a subsequence [2, 8]. Their OR is (2 | 8 = 10, which is 1010 in binary).

Array remains [2, 1].

Choose a subsequence [2]. OR will be the number itself (2, which is 10 in binary).

Array remains [1].

Choose a subsequence [1]. OR will be the number itself (1, which is 1 in binary).

The array becomes empty. So the answer is YES.

Function description 



Complete the removeOR function provided in the editor. This function takes the following 2 parameters and returns the answer YES or NO: 



N: Represents the number of elements

A: Represents the array A

Input format 



Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).



The first line contains T denoting the number of test cases. T also specifies the number of times you have to run the removeOR function on a different set of inputs.

For each test case:

The first line contains a single integer N denoting the number of elements.

The next line contains N space-separated integers denoting the elements of array A.

Output format 



For each test case, you have to print either YES or NO depending on whether it is possible to make the array empty after some number of operations.



    ***********************************************************
*/

import java.io.*;
import java.util.*;


public class TestClass {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine().trim());
        for(int t_i = 0; t_i < T; t_i++)
        {
            int N = Integer.parseInt(br.readLine().trim());
            String[] arr_A = br.readLine().split(" ");
            int[] A = new int[N];
            for(int i_A = 0; i_A < arr_A.length; i_A++)
            {
                A[i_A] = Integer.parseInt(arr_A[i_A]);
            }

            String out_ = removeOR(N, A);
            System.out.println(out_);
            
         }

         wr.close();
         br.close();
    }
    static String removeOR(int N, int[] A){
       // write your code here
        String result = "";
        int[] a = new int[32];
        int e = -1, o = -1;
        for(int i = 0 ; i < N; i++){
            // System.out.println(" "+ (A[i]&(A[i]>>1)));
            if((A[i] & (A[i]>>1))!=0){ result = "NO"; break; }
            boolean odd = false;
            boolean even = false;
            for(int j=31;j>=0;j--){
                boolean is = ((A[i] &(1<<j))>0);
                if(is && j%2 == 1) odd = true;
                if(is && j%2 == 0) even = true;
                a[j] += is?1:0;
                if(a[j]>0){ if(j%2==1) o=Math.max(o,j); else e = Math.max(e,j); }
            }
            if(odd && even) { result = "NO"; break; }
        }
        
        for(int i = e-2; i>=0; i-=2 ) {
            if(a[i]<a[i+2]) result = "NO";
        }
      
        for(int i = o; i>=0; i-=2 ) {
            // System.out.println(a[i]);
            if(a[i]<a[o]) 
            result = "NO";
        }
        if(result.length() == 0) result ="YES";
        return result;
    
    }
}