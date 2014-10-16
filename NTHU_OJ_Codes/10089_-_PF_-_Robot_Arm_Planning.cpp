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
int t, n, x1, y1, x2, y2, ans;
int cal[10];
const double SQRT = 70.7106781187;
double dx[] = {0, SQRT, 100, SQRT, 0, -SQRT, -100, -SQRT};
double dy[] = {100, SQRT, 0, -SQRT, -100, -SQRT, 0, SQRT};
int deg[] = {0, 45, 90, 135, 180, 225, 270, 315};
int mv[] = {0, 1, 2, 3, 4, 3, 2, 1};
int valid(double x, double y) {
	return x - 10.0 > x1 && x + 10.0 < x2 && y + 10.0 < y2 && y - 10.0 > y1;
}
int move() {
	int tot, ans = 1e9;
	vector<int> v;
	for (int i = 0; i < 8; i++)
		if (cal[i])
			v.push_back(i);
	sort(v.begin(), v.end());
	do {
		tot = min(360 - deg[v[0]], deg[v[0]]);
		for (int i = 1; i < v.size(); i++)
			tot += min(360 - abs(deg[v[i]] - deg[v[i - 1]]), abs(deg[v[i]] - deg[v[i - 1]]));
		ans = min(ans, tot);
	} while (next_permutation(v.begin(), v.end()));
	return ans / 45;
}
void dfs(int lv, int tot) {
	if (lv == 8 && tot == n) {
		double x = 0, y = 0;
		for (int i = 0; i < 8; i++) {
			x += dx[i] * cal[i];
			y += dy[i] * cal[i];
		}
		if (valid(x, y)) {
			ans = min(ans, move());
		}
	}
	if (lv == 8)
		return;
	for (int i = 0; i + tot <= n; i++) {
		cal[lv] = i;
		dfs(lv + 1, tot + i);
	}
}
int main(int argc, char *argv[]) {
	cin >> t;
	while (t--) {
		cin >> n >> x1 >> y1 >> x2 >> y2;
		ans = 1e9;
		dfs(0, 0);
		printf("%d\n", ans == 1e9 ? -1 : ans);
	}
	return 0;
}