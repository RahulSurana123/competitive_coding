
"""
Problem Description

Given an integer array A of size N. Return 1 if the array can be rearranged to form an arithmetic progression, otherwise, return 0.

A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.



Problem Constraints

2 <= N <= 105

-109 <= A[i] <= 109



Input Format

First and only argument is an integer array A of size N.



Output Format

Return 1 if the array can be rearranged to form an arithmetic progression, otherwise, return 0



Example Input

Input 1:

 A = [3, 5, 1]
Input 2:

 A = [2, 4, 1]


Example Output

Output 1:

 1
Output 2:

 0


Example Explanation

Explanation 1:

 We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
Explanation 2:

 There is no way to reorder the elements to obtain an arithmetic progression.
 """

[1,2,4,3,5,2]



def quick(s,e,A):
	if(s >= e): 
		return [ A[s] ]
	x = A[e]
	i =0
	j = e-1
	a = []
	b = []
	while(i<j):
		if(A[i]>x):
			a.append(A[i])
		else:
			b.append(A[i])
	a = quick(s,i-1,a)
	b = quick(i+1,e,b)
	# print(a)

	a.append(x)
	return a+b



A = [1, 2, 4, 3]

A = quick(0,len(A)-1,A)

print(A)

d = A[1]-A[0]
f = False

for i in range(2,len(A)):
	if (d != A[i]-A[i-1]):
		f = True
		break

if f:
	print(0)
else:
	print(1)