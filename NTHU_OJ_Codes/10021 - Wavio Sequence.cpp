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
int s[10001], a[10001], b[10001];
void LIS(int array[], int ans[], int n) {
	vector<int> v;
	v.push_back(array[0]);
	ans[0] = 1;
	for (int i = 1; i < n; i++) {
		int x = array[i];
		if (v.back() < x)
			v.push_back(x);
		else
			*(lower_bound(v.begin(), v.end(), x)) = x;
		ans[i] = v.size();
	}
}
int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) > 0) {
		for (int i = 0; i < n; i++)
			scanf("%d", s + i);
		LIS(s, a, n);
		reverse(s, s + n);
		LIS(s, b, n);
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, 2 * min(a[i], b[n - i - 1]) - 1);
		printf("%d\n", ans);
	}
	return 0;
}