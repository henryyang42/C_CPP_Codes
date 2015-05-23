import sys
input = file(sys.argv[1])


def solve(n, s):
    u = 1<<63
    l = 0
    mid = 0
    n -= 1
    m = -1
    ans = 0
    tot = 0
    while u >= l:
        tot = 0
        mid = (u+l)/2
        for x in s:
            tot += mid / x
        if tot > n:
            u = mid-1
        else:
            l = mid+1

    if tot == n:
        for i, x in enumerate(s):
            if mid % x > m:
                m = mid % x
                ans = i+1

    return ans


for case in range(int(input.readline())):
    vs = [int(x) for x in input.readline().split()]
    vals = [int(x) for x in input.readline().split()]
    print "Case #%d: %d" % (case+1, solve(vs[1], vals))
