import sys
input = file(sys.argv[1])

def solve(x, r, c):
    if (r*c) % x == 0 and (r*c) / x > 1 and r >= x and c >= x:
        return 'GABRIEL'
    return 'RICHARD'

for case in range(int(input.readline())):
    v = [int(x) for x in input.readline().split()]
    print "%s" % (str(v)+solve(v[0], v[1], v[2]))

