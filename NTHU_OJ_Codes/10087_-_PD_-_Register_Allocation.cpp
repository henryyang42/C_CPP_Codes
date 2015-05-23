#include <stdio.h>
#include <cstring>
#include <queue>
#include<algorithm>
#include<map>
#include<vector>
#include<iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		vector<pair<int, int> > v;
		for (int i = 0; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			v.push_back(make_pair(a, 1));
			v.push_back(make_pair(b, 2));
		}
		sort(v.begin(), v.end());
		int ind = 0, tmp = 0, ans = 0;
		for (int i = 0; i < 40000; i++) {
			while (ind < v.size() && v[ind].first == i) {
				tmp += v[ind].second == 1 ? 1 : -1;
				ans = max(ans, tmp);
				ind++;
			}
		}
		printf("%d\n" , ans);
	}
	return 0;
}