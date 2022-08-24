


A = [4,5,6,7,0,1,2]
target = 1

def binarySearch(target,A,s,e):
	
	while(s < e):
		m = (s+e) //2
		if(A[m] == target):
			return m
		elif(A[m] > target and A[s] >= target):
			s = m
		elif(A[m] > target and A[s] < target):
			e = m-1
		elif(A[m] < target):
			s = m+1
		# print(s,e,m)		
	if A[s] != target:
		return -1
	return s

print( binarySearch(target,A,0,len(A)-1))