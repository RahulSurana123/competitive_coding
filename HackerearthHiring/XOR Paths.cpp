

/* 

    Solution by Rahul Surana

    ***********************************************************


You are given the following: 

	A tree  T  consisting of  n  nodes 
	An integer  x  
 

Each node has some value  w[i]  associated with it .   

  Task  

Determine the number of simple paths in the tree, such that the bitwise xor of elements on the simple path is  x . 

Note: A simple path between node  u  and  v  is defined as a sequence of edges that connects node  u  and  v  and includes the occurrence of a node at most once. 

Example  

Assumptions  

 
  n = 3  
  w = [3,2,2]  
  edges = [(1,2), (1,3)]  
  x = 1  
 

Approach :
 
There exist two simple paths such that bitwise xor of elements on the path is  x  
Two paths are from node  1  to node  2 = 1 and node  1  to node  3 = 1, where | is Bitwise Xor operator. 

Therefore, print  2.  
 

Function description  

Complete the  xor_paths  function provided in the editor. This function takes the following 4 parameters and returns the answer: 

 
	n : Represents the number of nodes in the tree 
	w : Represents the value associated with each node 
	x : Represents bitwise xor of elements on the simple path 
	edges : Represents a 2D array containing  n-1  edges representing edges in the tree. 
 

Input format : 

Note : This is the input format that you must use to provide custom input (available above the Compile and Test button). 

The first line contains an integer  t  denoting the number of test cases.  t  also specifies the number of times you have to run the  xor_paths  function on a different set of inputs 
For each test case:
	The first line contains a single integer  n  denoting the number of nodes. 
	The second line contains n space-separated integers representing array  w . 
	The third line contains a single integer  x . 
	n-1  lines follow, each containing two space-separated integers representing   an edge between node  u  and  v . 
	 
	 
 

Output format :

For each test case, print the answer in a new line. 

 
 

Constraints:  

1 <= t <= 10 
1 <= n <= 10^5 
1 <= u, v <= n  
u  != v  
0 <= w[i], x <= 15 



    ***********************************************************
*/