t = [-1 for i in range((4*100001))] 

def build(arr):
    # z = -1
    for i in range(len(arr)):
        if(arr[i] < 0):
            # z = i
            t[len(arr)+i] = i
        # else:
        #     t[len(arr)+i] = z
    for i in range(len(arr)-1,0,-1):
        t[i] = min(t[i<<1] if t[i<<1] != -1 else len(arr)+1 ,t[i<<1 | 1] if t[i<<1 | 1] != -1 else len(arr)+1)
        if(t[i] == len(arr)+1):
            t[i] = -1
    # print(t[0:100])

def query(l,r,arr):
    res = -1
    l+=len(arr)
    r+=len(arr)
    while(l<r):
        if(l&1):
            res = min(t[l] if t[l] != -1 else len(arr)+1, res if res != -1 else len(arr)+1)
            if(res == len(arr)+1): 
                res = -1
        if(r&1):
            res = min(t[r] if t[r] != -1 else len(arr)+1, res if res != -1 else len(arr)+1)
            if(res == len(arr)+1): 
                res = -1
        l>>=1
        r>>=1
        print(l,r,res)
    return res
        


def first_place (N, Q, A, Query):
    # z = []
    # s = 0
    # p = set()
    # n = set()
    # for i in range(len(A)):
    #     if(A[i] < 0):
    #         n.add(i)
    #     else:
    #         p.add(i)
    # t = SegmentTree(A)
    ans = []
    for x in Query:
        if(x[0] == 1):
            for i in range(x[1]-1, x[2]):
                A[i] = -A[i]
            # build(A)
        else:
            # a = query(x[1]-1,x[2],A)
            f = True
            for i in range(x[1]-1,x[2]):
                if(A[i]<0):
                    f = False
                    ans.append(i+1);
                    break
            if(f):
                ans.append(-1) 
    return ans 

N, Q = map(int, raw_input().split())
A = map(int, raw_input().split())
Query = []
for _ in xrange(Q):
    Query.append(map(int, raw_input().split()))

out_ = first_place(N, Q, A, Query)
print ('\n'.join(map(str, out_)))