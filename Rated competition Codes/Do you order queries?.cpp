	
/* 

    Solution by Rahul Surana

    ***********************************************************


	You are given n (1 <= n <= 300000) queries. Each query is one of $3$ types:

	1. add pair (a, b) to the set. (-10^9 <= a, b <= 10^9)

	2. remove a pair added in query index (All queries are numbered with integers from 1 to n).

	3. For a given integer A find the maximal value a·A + b over all pairs (a, b) from the set. (-10^9 <= A <= 10^9). It is guaranteed that the set of pair will not be *empty*.

	 

	INPUT.

	The first line contains integer n (1 <= n <= 3·10^5) - the number of queries.
	Each of next n lines starts with integer op (1 <= op <= 3) - the type of query.

	 

	OUTPUT

	For each query of $3$ type print on a separate line the maximal value of $a·A + b$. It is guaranteed that the set of pair will not be *empty*.
	


    ***********************************************************
*/