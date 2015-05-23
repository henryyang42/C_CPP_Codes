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
#define Pair pair<int, int>
#define Vec vector<Pair >
#define Map map<string, Vec >
using namespace std;
int t, n, q, vol;
Map M;
bool cmp(const Pair &a, const Pair &b) {
	return a.first < b.first;
}
int can(int qa) {
	Map::iterator it = M.begin();
	int volume = 0;
	while (it != M.end() && volume <= vol) {
		Vec *v = &(it -> second);
		if (qa > v -> back().first)
			return 0;
		int Min = 2e9;
		Vec::iterator p = lower_bound(v->begin(), v->end(), Pair(qa, 0), cmp);
		while (p != v -> end()) {
			Min = min(p->second, Min);
			p++;
		}
		volume += Min;
		it++;
	}
	return volume <= vol;
}
int main(int argc, char *argv[]) {
	cin >> t;
	while (t--) {
		scanf("%d%d", &n, &vol);
		M.clear();
		int Max = 0;
		for (int i = 0; i < n; i++) {
			char key[100], gg[100];
			int vo, qa;
			scanf("%s%s%d%d", key, gg, &vo, &qa);
			M[string(key)].push_back(make_pair(qa, vo));
			Max = max(qa, Max);
		}
		Map::iterator it = M.begin();
		while (it != M.end()) {
			Vec *v = &(it -> second);
			sort(v -> begin(), v -> end());
			it++;
		}
		int lower = 0, upper = Max, mid, ans;
		while (upper >= lower) {
			mid = (upper + lower) >> 1;
			if (can(mid))
				ans = mid, lower = mid + 1;
			else
				upper = mid - 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}