

A = [ 2,6,6,7,1,5,14,14]


m = A[0]
ans = 0
j = 1
i = 0
while(i < len(A) and A[i] < m):
	i+=1
m = A[i]
while(j<len(A)):
	while( j < len(A) and A[j] > m): 
		j+=1
	ans += A[j-1]-m
	if(j+1 < len(A)):
		m = A[j]
	j+=1
	# print(m)
print(ans)