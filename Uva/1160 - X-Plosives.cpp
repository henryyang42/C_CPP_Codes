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
int g[100001], ans;
int find_(int x) {
	return g[x] == x ? x : (g[x] = find_(g[x]));
}
void init() {
	ans = 0;
	for (int i  = 0; i <= 100000; i++)
		g[i] = i;
}
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int a, b;
	init();
	while (scanf("%d", &a) > 0) {
		if (a == -1) {
			printf("%d\n", ans);
			init();
			continue;
		}
		scanf("%d", &b);
		int pa = find_(a), pb = find_(b);
		if (pa == pb) {
			ans++;
		}
		else
			g[pa] = pb;
	}
	return 0;
}