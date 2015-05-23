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
vector<int> v[10000];
int tran(int a, int i, int j) {
	int s[4];
	for (int k = 0; k < 4; k++)
		s[k] = a % 10, a /= 10;
	s[i] = (s[i] + (j ? 1 : -1) + 10) % 10;
	for (int k = 3; k >= 0; k--)
		a = a * 10 + s[k];
	return a;
}
int get() {
	int tot = 0, x;
	for (int i = 0; i < 4; i++)
		scanf("%d", &x), tot = tot * 10 + x;
	return tot;
}
int main(int argc, char *argv[]) {
	int visit[10000] = {};
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int a = q.front(); q.pop();
		visit[a] = 1;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 2; j++) {
				int b = tran(a, i, j);
				v[a].push_back(b);
				if (!visit[b])
					q.push(b), visit[b] = 1;
			}
	}
	int t;
	cin >> t;
	while (t--) {
		int st, ed, gg[10000] = {}, n, visit[10000] = {};
		st = get(); ed = get();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			gg[get()] = 1;
		queue<int>Q;
		Q.push(st);
		Q.push(0);
		int ans = -1;
		while (!Q.empty()) {
			int a = Q.front(); Q.pop();
			int len = Q.front(); Q.pop();
			if (a == ed) {
				ans = len;
				break;
			}
			for (int i = 0; i < v[a].size(); i++) {
				int b = v[a][i];
				if (!visit[b] && !gg[b]) {
					visit[b] = 1;
					Q.push(b);
					Q.push(len + 1);
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}