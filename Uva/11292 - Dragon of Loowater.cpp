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
using namespace std;

int main(int argc, char *argv[]) {
	int n, m, dragon[20001], knight[20001];
	while (scanf("%d%d", &n, &m), n + m) {
		for (int i = 0; i < n; i++)
			scanf("%d", dragon + i);
		for (int i = 0; i < m; i++)
			scanf("%d", knight + i);
		sort(dragon, dragon + n);
		sort(knight, knight + m);
		long long ans = 0, ct = 0, ind = 0;
		for (int i = 0; i < m && ct < n; i++) {
			if (knight[i] >= dragon[ind]) {
				ct++;
				ind++;
				ans += knight[i];
			}
		}
		if (ct < n)
			puts("Loowater is doomed!");
		else
			printf("%lld\n", ans);
	}
	return 0;
}