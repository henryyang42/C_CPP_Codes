#include <vector>
#include <cstdio>
using namespace std;
#define MAX 50000
vector<int> v[MAX];
int mark[MAX], tmp[MAX], c, n;
void init() {
    for (int i = 0; i < MAX; i++) {
        v[i].clear();
        mark[i] = 0;
    }
}
void a_c(int x, int vx, int y, int vy) {
    x = 2 * x + vx;
    y = 2 * y + vy;
    v[x ^ 1].push_back(y);
    v[y ^ 1].push_back(x);
}
int dfs(int x) {
    if (mark[x ^ 1]) return 0;
    if (mark[x]) return 1;
    mark[x] = 1;
    tmp[c++] = x;
    for (int i = 0; i < v[x].size(); i++) {
        if (!dfs(v[x][i]))
            return 0;
    }
    return 1;
}
int solve() {
    for (int i = 0; i < 2 * n; i += 2) {
        if (!mark[i] && !mark[i + 1]) {
            c = 0;
            if (!dfs(i)) {
                while (c > 0) mark[tmp[--c]] = 0;
                if (!dfs(i + 1))
                    return 0;
            }
        }
    }
    return 1;
}
int main() {
    int t, m;
    scanf("%d", &t);
    while (t--) {
        init();
        scanf("%d%d", &n, &m);
        while (m--) {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            a_c(x, !c, y, !c);
        }
        if (solve())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

