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
using namespace std;
int g[20001], t, n, dis[20001];
int find_(int x) {
	if (g[x] != x) {
		int root = find_(g[x]);
		dis[x] += dis[g[x]];
		return g[x] = root;
	}
	return x;
}
void init() {
	for (int i  = 0; i <= n; i++)
		g[i] = i, dis[i] = 0;
}
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	cin >> t;
	while (t--) {
		cin >> n;
		init();
		string str;
		while (cin >> str, str != "O") {
			int u, v;
			if (str == "I") {
				cin >> u >> v;
				dis[u] = abs(u - v) %  1000;
				g[u] = v;
			}
			else {
				cin >> u;
				find_(u);
				printf("%d\n", dis[u]);
			}
		}
	}
	return 0;
}