import sys
input = file(sys.argv[1])
#input = file('sample.in')
def rev(s):
    if s % 10 == 0:
        return s
    return int(str(s)[::-1])


def solve1(s):
    ans = 0
    while s > 0:
        ans += 1
        if s > 1 and rev(s) < s and s % 10 == 1:
            s = rev(s)
        else:
            s -= 1
    #    print s,
    #print
    return ans

for case in range(int(input.readline())):
    s = int(input.readline())
    print "Case #%d: %d" % (case+1, solve1(s))
