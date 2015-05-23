#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define MAX 1000001
int s[MAX], t[MAX], m[MAX][20], inv[MAX];
void trans(int n) {
	int tot = 0;
	for (int i = 0; i < n; i++) {
		int ct = 0;
		while (i + ct < n && s[i + ct] == s[i])
			ct++;
		for (int j = i; j < i + ct; j++)
			inv[j] = tot, t[j] = ct;
		tot += ct;
		i += ct - 1;
	}
}
void build(int n) {
	for (int i = 0; i < n; i++)
		m[i][0] = t[i];
	for (int j = 1; 1 << j <= n; j++) {
		int sz = 1 << (j - 1);
		for (int i = 0; i + sz < n; i++)
			m[i][j] = max(m[i][j - 1], m[i + sz][j - 1]);
	}
}
int query(int a, int b) {
	int k = 31 - __builtin_clz(b - a + 1);
	return max(m[a][k], m[b - (1 << k) + 1][k]);
}
int main(int argc, char *argv[]) {
	int n, q, a, b;
	while (scanf("%d", &n), n > 0) {
		scanf("%d", &q);
		for (int i = 0; i < n; i++)
			scanf("%d", s + i);
		trans(n);
		build(n);
		while (q--) {
			scanf("%d%d", &a, &b);
			a--, b--;
			if (inv[a] == inv[b])
				printf("%d\n", b - a + 1);
			else {
				int ra = a == inv[a] ? a : inv[a] + t[inv[a]];
				int rb = inv[b];
				int ans = max(ra - a, b - rb + 1);
				if (ra < rb)
					ans = max(ans, query(ra, rb - 1));
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}