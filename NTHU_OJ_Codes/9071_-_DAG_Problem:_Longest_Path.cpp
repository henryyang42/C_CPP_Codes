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
int st, ed, n, ans, a, b;
map<int, vector<int> > m;
void dfs(int x, int lv) {
	if (x == ed) {
		ans = max(lv, ans);
		return;
	}
	vector<int> v  = m[x];
	for (int i = 0; i < v.size(); i++) {
		dfs(v[i], lv + 1);
	}
}
int main(int argc, char *argv[]) {
	int kase = 0;
	while (scanf("%d%d", &st, &ed), st + ed) {
		m.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			m[a].push_back(b);
		}
		ans = -1;
		dfs(st, 0);
		printf("Case %d: ", ++kase);
		if (ans == -1)
			puts("INVALID");
		else
			printf("%d\n", ans);
	}
	return 0;
}