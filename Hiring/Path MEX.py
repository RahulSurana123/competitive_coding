

'''


             Solution by Rahul Surana


************************************************************************************

Path MEX

You are given a rooted tree having N nodes. A tree is a connected undirected graph with N−1 edges. 
Here root node is node 1. Each node has some integer value val(i) associated with it.

Task

For each node i (1 &lt;= i &lt;= N), print MEX of the path values from the root node to node i. 

Notes


    Assume 1-based indexing. 
    The MEX of an array is equal to the smallest positive integer that is not present in the array. For example, MEX(1, 2, 4, 2, 3, 6, 7) = 5.


Example

Assumptions


    N = 4
    val = [1, 3, 2, 8] 
    parent = [1, 2, 2]


Approach


    Node 1: MEX(1) = 2
    Node 2: MEX(1, 3) = 2
    Node 3: MEX(1, 3, 2) = 4
    Node 4: MEX(1, 3, 8) = 2
    Hence, required answer is [2, 2, 4, 2].


Function description

Complete the function solve provided in the editor. This function takes the following 3 parameters and returns the required answer:


    N: Represents the number of nodes
    val: Represents the value of nodes
    parent: Represents parent node where parent<sub>i</sub> is the parent node of node i + 1 (1 &lt;= i &lt;= N - 1)  


Input format

Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).


    The first line contains T denoting the number of test cases. T also specifies the number of times you have to run the solve function on a different set of inputs.
    For each test case:
    
        The first line contains N denoting the number of nodes.
        The second line contains N space-separated integer denoting the values of nodes.
        The third line contains N - 1 space-separated integer denoting the parent nodes.
    
    


Output format

For each test case, print N space-separated integers in a new line, where i<sup>th</sup> value represents the required MEX value for node i.


************************************************************************************************


'''


from collections import defaultdict
# Write your code here

def mex(l):
    mex = 1
    while mex in l:
        mex+=1
    return mex

def df(val,adj,ans,node,path):
    if(node not in adj.keys()):
        adj[node] = []
    for j in adj[node]:
        p = path+[val[j]]
        # d = ans[node]
        # if(val[j]==d):
        #     ans[j] = d+1
        # else:
        #     ans[j] = d
        ans[j] = mex(p)
        df(val,adj,ans,j,p)


for i in range(int(input())):
    n = int(input())
    val = [int(j) for j in input().split()]
    p = [int(j) for j in input().split()]
    adj = defaultdict(lambda:[])
    ans = [0] * n  
    for j in range(len(p)):
        adj[p[j]-1].append(j+1)
#     print(adj)
    
    if(val[0]==1):
        ans[0] = 2
    else:
        ans[0] = 1
    l = [val[0]]
    df(val,adj,ans,0,l)
    print(" ".join([str(j) for j in ans]))