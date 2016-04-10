import sys

input = file(sys.argv[1])


TURN_LEFT, TURN_RIGHT, TURN_NONE = (1, -1, 0)

def turn(p, q, r):
    """Returns -1, 0, 1 if p,q,r forms a right, straight, or left turn."""
    return cmp((q[0] - p[0])*(r[1] - p[1]) - (r[0] - p[0])*(q[1] - p[1]), 0)

def _dist(p, q):
    """Returns the squared Euclidean distance between p and q."""
    dx, dy = q[0] - p[0], q[1] - p[1]
    return dx * dx + dy * dy

def _next_hull_pt(points, p):
    """Returns the next point on the convex hull in CCW from p."""
    q = points[0] != p and points[0] or points[1]
    for r in (x for x in points if x != p):
        if turn(p, q, r) == TURN_RIGHT:
            q = r
    return q

def _next_hull_pt(points, p):
    """Returns the next point on the convex hull in CCW from p."""
    q = p
    for r in points:
        t = turn(p, q, r)
        if t == TURN_RIGHT or t == TURN_NONE and _dist(p, r) > _dist(p, q):
            q = r
    return q

def convex_hull(points):
    """Returns the points on the convex hull of points in CCW order."""
    hull = [min(points)]
    for p in hull:
        q = _next_hull_pt(points, p)
        if q != hull[0]:
            hull.append(q)
    ass = []
    hull_len = len(hull)
    for p in points:
        for k in range(hull_len):
            if (p not in hull) and collinear(p, hull[k], hull[(k+1)%hull_len]):
                ass.append(p)
    hull = ass + hull
    return hull

def collinear(p0, p1, p2):
    x1, y1 = p1[0] - p0[0], p1[1] - p0[1]
    x2, y2 = p2[0] - p0[0], p2[1] - p0[1]
    return x1 * y2 - x2 * y1 < 1e-12

def solve(n, s):
    ans = [n]*n
    m = 0
    for i in range(1<<n):
        ss = []
        for j in range(n):
            if (i>>j)&1:
                ss.append(s[j])
        if len(ss) < 3:
            continue
        hull = convex_hull(ss)
        l = len(ss)
        for i in range(n):
            if s[i] in hull:
                ans[i] = min(ans[i], n-l)
    for i in range(n):
        print ans[i]


for case in range(int(input.readline())):
    n = int(input.readline())
    vals = []
    for i in range(n):
        vals += [[int(x) for x in input.readline().split()]]
    print "Case #%d:" % (case+1)
    solve(n, vals)
