#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define M 1000000007
#define MAX 2015
using namespace std;
long long f[MAX][MAX], c[MAX];
int main(int argc, char *argv[]) {
    f[1][0] = 1;
    for (int b = 0; b < MAX; b++) {
        for (int a = b + 1; a < MAX - 1; a++) {
            f[a + 1][b] = (f[a + 1][b] + f[a][b]) % M;
            f[a][b + 1] = (f[a][b + 1] + f[a][b]) % M;
        }
    }

    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int T;
    cin >> T;
    for (int TT = 1; TT <= T; TT++) {
        int a, b;
        scanf("%d-%d", &a, &b);

        printf("Case #%d: %lld %lld\n", TT, f[a][b], f[b + 1][b + 1]);
    }
    return 0;
}