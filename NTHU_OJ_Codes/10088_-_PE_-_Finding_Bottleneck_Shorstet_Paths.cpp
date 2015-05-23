#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
int g[10000];
int pt[1000][2];
int find_(int x) {
	return g[x] == x ? x : (g[x] = find_(g[x]));
}
vector< pair<int, pair<int, int> > > v;

int main() {
	int n, i, a, b;
	while (scanf("%d", &n), n) {
		for (i = 0; i < n; i++)
			scanf("%d %d", &pt[i][0], &pt[i][1]);
		scanf("%d %d", &a, &b); a--, b--;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				int dis = (pt[i][0] - pt[j][0]) * (pt[i][0] - pt[j][0]) + (pt[i][1] - pt[j][1]) * (pt[i][1] - pt[j][1]);
				v.push_back(make_pair(dis, make_pair(i, j)));
			}
		sort(v.begin(), v.end());
		for (int i = 0; i < 10000; i++)
			g[i] = i;
		int ind = 0;
		while (1) {
			int pa = find_(v[ind].second.first);
			int pb = find_(v[ind].second.second);
			if (pa != pb)
				g[pa] = pb;
			if (find_(a) == find_(b)) {
				printf("%d\n", v[ind].first);
				break;
			}
			ind++;
		}
	}
	return 0;
}