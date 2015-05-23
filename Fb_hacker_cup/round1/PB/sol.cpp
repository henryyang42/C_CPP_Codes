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
#define MAX 1500000
#define idx(c) (c-'a')
using namespace std;
char s[MAX];
int ch[MAX][26], val[MAX], sz;
void Trie() {
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
    memset(val, 0, sizeof(val));
}
int insert(char s[]) {
    int u = 0, len = strlen(s), ans = 1e9;
    for (int i = 0; i < len; i++) {
        int c = idx(s[i]);
        if (!ch[u][c]) {
            ch[u][c] = sz;
            memset(ch[sz], 0, sizeof(ch[sz]));
            ans = min(ans, i + 1);
            sz++;
        }
        u = ch[u][c];
        if (i == len - 1)
            val[u]++;
    }
    return min(ans, len);
}
int main(int argc, char *argv[]) {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int T, N;
    cin >> T;
    for (int TT = 1; TT <= T; TT++) {
        long long ans = 0;
        cin >> N;
        Trie();
        for (int i = 0; i < N; i++) {
            scanf("%s", s);
            ans += insert(s);
        }
        printf("Case #%d: %lld\n", TT, ans);
    }
    return 0;
}