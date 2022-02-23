



"""
1.
Problem Description

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Problem Constraints

1 <= N <= 1000000
0 <= A[i] <= 2

Input Format

First and only argument of input contains an integer array A.


Output Format

Return an integer array in asked order


Example Input

Input 1 :
    A = [0 1 2 0 1 2]
Input 2:

    A = [0]


Example Output

Output 1:
    [0 0 1 1 2 2]
Output 2:

    [0]


Example Explanation

Explanation 1:
    [0 0 1 1 2 2] is the required order.
"""



A = [1,0, 1, 1, 2, 2]
i = 0
j = len(A)-1
k = 0
while(k < len(A)):
  if A[k] == 0:
  	A[i],A[k] = A[k],A[i]
  	i+=1
  	k+=1
  elif A[k] == 2:
    j-=1
    k+=1
  else:
  	A[k],A[j] = A[j],A[k]
  	k+=1
print(A)
    
  
  