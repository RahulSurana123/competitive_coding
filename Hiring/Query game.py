

'''

Solution by Rahul Surana
    


**********************************************************************************************


You are also given Q queries of the form: 


	1 0 0: Reverse the array A
	2 i j: Swap the elements A[i] and A[j]
	3 x 0:  Print the position of element x in array A


Task

Print the position of x in array A after each query of type 3.

Note: 1-based indexing is followed.

Example 

Assumptions


	N = 4
	A = [1, 2, 3, 4]
	Q = 4
	Queries = [[ 2 2 4 ], [ 3 2 0 ], [ 1 0 0 ], [ 3 1 0 ]]


Approach


	The first query is of type 2, and i and j are 2 and 4 respectively. So you swap A[2], A[4]. Array A becomes [1, 4, 3, 2].
	The second query is of type 3, and x is 2. So you need to output index of 2 in array A, so the output is 4.
	The third query is of type 1. So you reverse array A. A= [2, 3, 4, 1].
	The last query is of type 3, and x is  1.  So you need to output index of 1 in array A, so the output is 4.


Hence, the answer is [4 4].

Function description:

Complete the function query_game provided in the editor. This function takes the following 4 parameters and returns the required answer:


	N: Represents the size of array A
	A: Represents the elements of array A
	Q: Represent the number of queries
	P: Represents the queries in form of 2D array with Q rows and 3 columns


Input format:

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).


	The first line contains T denoting the number of test cases. T also specifies the number of times you have to run the query_game function on a different set of inputs.
	For each test case:
	
		The first line contains a single integer N denoting the size of array A.
		The second line contains N space-separated values, denoting the elements of A.
		The third line contains a single integer Q denoting the number of queries. 
		Q lines follow, each containing queries in the form of 3 space-separated integers.
	
	


Output format:

For each test case in a new line, print the index of x in array A for each query of type 3 in space-separated format.


***************************************************************************************


'''





def query_game (N, A, Q, P):
    flag = True
    ans = []
    # first = True
    # second = True
    # A = [0] + A
    for i in range(Q):
        # print(A)
        if(P[i][0] == 1):
            # pass
            # A.reverse()
            if(flag):
                flag = False
            else:
                flag = True
        elif(P[i][0] == 2):
            a = P[i][1]
            b = P[i][2]
            # if(second):
            #     a-=1
            #     b-=1
                # second = False
            if(flag):
                A[a-1],A[b-1] = A[b-1],A[a-1]
            else:
                A[-a],A[-b] = A[-b],A[-a]
        else:
            ind = P[i][1]
            # if(first):
            #     ind -=1
                # first = False
            j = A.index(ind)
            if(flag):
                ans.append(j+1)
            else:
                ans.append(N-j)
    # for i in ans:
    #     print(i)
    return ans

T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    Q = int(input())
    P = [list(map(int, input().split())) for i in range(Q)]

    out_ = query_game(N, A, Q, P)
    print (' '.join(map(str, out_)))