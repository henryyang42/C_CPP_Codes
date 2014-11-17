#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define M 20071027
using namespace std;
char s[400000], tok[10000];
long long dp[400000];

int ch[400001][26];
int val[400001];
int sz;

void Trie() {
	sz = 1;
	memset(ch[0], 0, sizeof(ch[0]));
	memset(val, 0, sizeof(val));
}
int idx(char c) {
	return c - 'a';
}
void insert(char s[]) {
	int u = 0, len = strlen(s);
	for (int i = 0; i < len; i++) {
		int c = idx(s[i]);
		if (!ch[u][c]) {
			ch[u][c] = sz;
			memset(ch[sz], 0, sizeof(ch[sz]));
			sz++;
		}
		u = ch[u][c];
		if (i == len - 1)
			val[u] = 1;
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n, kase = 0;
	while (scanf("%s", s + 1) > 0) {
		memset(dp, 0, sizeof(dp));
		Trie();
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%s", tok);
			insert(tok);
		}
		int len = strlen(s + 1);
		dp[0] = 1;
		for (int i = 1; i <= len; i++) {
			long long va = dp[i - 1];
			int u = 0, ii = i;
			while (ii <= len && ch[u][idx(s[ii])]) {
				u = ch[u][idx(s[ii])];
				if (val[u])
					dp[ii] = (dp[ii] + va) % M;
				ii++;
			}
		}
		printf("Case %d: %lld\n", ++kase, dp[len] % M);
	}
	return 0;
}