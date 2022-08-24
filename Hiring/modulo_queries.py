import math
from collections import defaultdict

def modulo_queries (Q, queries):
    f = defaultdict(lambda: 0)
    c = defaultdict(lambda: 0)
    ans = []
    for i in range(Q):
        # print(queries[i])
        if(queries[i][0] == 1):
            f[queries[i][1]] += queries[i][2]
            c[queries[i][1]] += 1
        else:
            z = pow(2,int(math.log(queries[i][1],2)+1))
            cc = 0
            ff = 0
            # print(z)
            for k,v in c.iteritems():
                if(k%z == queries[i][1]):
                    # print(f[k])
                    ff += f[k]
                    cc += c[k]
                # print(k%z)
            # print(cc,ff)
            # print([cc,ff])
            ans.append([cc,ff])
    return ans


T = input()
for _ in xrange(T):
    Q = input()
    queries = []
    for _ in xrange(Q):
        queries.append(map(int, raw_input().split()))

    out_ = modulo_queries(Q, queries)
    for i_out_ in out_:
        print ' '.join(map(str, i_out_))