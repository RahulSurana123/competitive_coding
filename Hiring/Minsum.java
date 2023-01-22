/* 

    Solution by Rahul Surana

    ***********************************************************

Minsum
You are given N integers in an array A. Let us define a function F(x) as:


Your Score is defined as follows:


Task

Determine the following:

Score
The number of values of x such that x 
  and F(x) = Score.
Note: 
 represents the bitwise xor operator.

Example

Assumptions

N = 1
A = [0]
Approach

In this example, the value of the Score would be 0. There is only one value of x for which F(x) is equal to Score and that value is 0.

Function description

Complete the solve function provided in the editor. The function takes the following 2 parameters and returns your Score and the number of values of x as mentioned:

N: Represents the length of array A
A: Represents an array consisting of N integers
Input format

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

The first line contains a single integer T, which denotes the number of test cases. T also specifies the number of times you have to run the solve function on a different set of inputs.
For each test case:
The first line contains an integer N denoting the length of array A.
The second line contains N space-separated integers denoting the elements of the array A.
Output format

For each test case, print two space-separated integer values in a new line. The first integer represents your Score and the second integer represents the number of different values of x for which this Score is attainable as described in the problem. <div class="problem-description assessment-problem-description new-nav-fs-problem-description" style="height: 206px;"><div class="algorithm" data-id="d4171f48c26d45f78f6f91c045944005"><div class="description-header width-100 padding-bottom-10 lighter-border-bottom margin-bottom-20 flex justify-between items-center"><div class="flex items-center justify-center"><div class="content-heading inline-block semi-bold margin-right-10">Question</div><div class="serial-number content-heading inline-block margin-right-8 serial-number-d4171f48c26d45f78f6f91c045944005">2 </div><div class="he-tooltip inline-block feedback-btn-tooltip he-tooltip-bottom" aria-label="Report issue with question" role="tooltip"><button type="button" class="btn-plain feedback-icon-btn flex items-center justify-center"><svg width="16" height="16" viewBox="0 0 16 16" fill="none" xmlns="http://www.w3.org/2000/svg"><path d="M8 7V4.66667M8 9.33333H8.00667M6.6 12.8L7.57333 14.0978C7.71808 14.2908 7.79045 14.3873 7.87918 14.4218C7.95689 14.452 8.04311 14.452 8.12082 14.4218C8.20955 14.3873 8.28192 14.2908 8.42667 14.0978L9.4 12.8C9.59543 12.5394 9.69315 12.4091 9.81234 12.3097C9.97126 12.177 10.1589 12.0832 10.3603 12.0357C10.5114 12 10.6743 12 11 12C11.9319 12 12.3978 12 12.7654 11.8478C13.2554 11.6448 13.6448 11.2554 13.8478 10.7654C14 10.3978 14 9.93188 14 9V5.2C14 4.0799 14 3.51984 13.782 3.09202C13.5903 2.71569 13.2843 2.40973 12.908 2.21799C12.4802 2 11.9201 2 10.8 2H5.2C4.0799 2 3.51984 2 3.09202 2.21799C2.71569 2.40973 2.40973 2.71569 2.21799 3.09202C2 3.51984 2 4.07989 2 5.2V9C2 9.93188 2 10.3978 2.15224 10.7654C2.35523 11.2554 2.74458 11.6448 3.23463 11.8478C3.60218 12 4.06812 12 5 12C5.32572 12 5.48858 12 5.63967 12.0357C5.84113 12.0832 6.02874 12.177 6.18766 12.3097C6.30685 12.4091 6.40457 12.5394 6.6 12.8Z" stroke="#116DE3" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round"></path></svg></button></div></div><div class="weight-600 black-333 inline-block"><div private_url_hash="d4171f48c26d45f78f6f91c045944005" class="algorithm-start-flow project-start-flow float-right inline-block padding-left-10 tool-tip flow-div-algorithm" title="See how to attempt this question."><i class="flow-help fa fa-question-circle font-size-16 light new-flow-help"></i></div><div class="problem-score max-marks inline-block max-marks-d4171f48c26d45f78f6f91c045944005">Max. score: 100.00</div></div></div><div class="clear"></div><div class="problem-statement problem-statement-d4171f48c26d45f78f6f91c045944005"><div class="semi-bold margin-bottom-20">Minsum</div><div class="algorithm-problem complete-problem-statement black-333"><p>You are given <em>N</em>&nbsp;integers in an array <em>A.</em>&nbsp;Let us define a function <em>F(x)</em>&nbsp;as:</p>


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

            long[] out_ = solve(N, A);
            System.out.print(out_[0]);
            for(int i_out_ = 1; i_out_ < out_.length; i_out_++)
            {
                System.out.print(" " + out_[i_out_]);
            }
            
            System.out.println();
            
         }

         wr.close();
         br.close();
    }
    static long[] solve(int N, int[] A){
       // write your code here
        long[] result = {0,0};
        long a[] = new long[32];
        for(int i = 0 ; i < N; i++){
            for(int j=31;j>=0;j--){
                boolean is = ((A[i] &(1<<j))>0);
                a[j] += is?1:0;
            }
        }
        long min = 0,c = 0;
        for(int i = 0; i < 32;i++){
            min += Math.min(a[i],(N-a[i]))*(1<<i);
            if(a[i] == N-a[i]) c+=1;
        }
        result[0] = min;
        result[1] = (long)(1<<c);
        return result;
    
    }
}