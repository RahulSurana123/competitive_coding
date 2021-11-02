

'''


             Solution by Rahul Surana


************************************************************************************

Cross sequence

You are given the following:


    An array A of size N
    An integer K


A cross sequence S is obtained from A by following process: 


    For each i,j in  1<= i , j <= N  calculate | Ai − Aj | and add | Ai - Aj | to S


Task

Determine the Kth smallest element in S.

Notes


    Assume 1-based indexing
    |x| denotes the absolute value of x.


Example

Assumptions


    N = 3
    A = [1, 2, 3]
    K = 7


the answer is 1.

Function description

Complete the function solve provided in the editor. This function takes the following 3 parameters and returns an integer as the answer:


    N: Represents the size of array A
    A: Represents the elements in A
    K: Represents the position of the element to be found in S


Input format

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).


    The first line contains T denoting the number of test cases. T also specifies the number of times you have to run the solve function on a different set of inputs.
    For each test case:
    
        The first line contains an integer N denoting the size of A.
        The second line contains N space-separated integers.
        The third line contains an integer denoting the value of K.
    
    


Output format

For each test case, print the answer in a new line representing the K<sup>th</sup> smallest element in S.


************************************************************************************************


'''



def solve (N, A, K):
    if(K<=N):
        return 0
    K=K-N
    K = int((K-1)/2)
    L = []
    # X = K
    # gap = 1
    # for i in range(1,len(A)):
    #     for j in range(len(A)-i):
    #         L.append(abs(A[j]-A[i+j]))
    #         # print(j,i+j)
    #     if(len(L)>=K):
    #         break
        # gap+=1
        
    # for i in range(len(A)):
    #     for j in range(i+1,len(A)):
    #         L.append(abs(A[i]-A[j]))
        #     L.append(abs(A[i]-A[j]))
#     print(L)
    L = [abs(A[i]-A[j]) for i in range(len(A)) for j in range(i+1,len(A))]
    L.sort()
    # print(L)
    return L[K]

for _ in range(int(input())):
    N = int(input())
    A = list(map(int, input().split()))
    K = int(input())

    out_ = solve(N, A, K)
    print (out_)