import sys
input = file(sys.argv[1])

def solve1(n, s):
    if n == 1:
        return 0
    else



for case in range(int(input.readline())):
    vals = []
    n = int(input.readline())
    for i in range(n):
        vals.append([int(x) for x in input.readline().split()])
    print "Case #%d: %d" % (case+1, solve1(n, vals))
