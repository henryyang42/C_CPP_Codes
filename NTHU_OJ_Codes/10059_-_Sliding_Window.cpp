#include<cstdio>
#include<deque>
using namespace std;
int s[1000005], n, k, ans[1000005][2];
pair<int, int> Q[1000005][2];
int head[2] = { -1, -1}, tail[2] = { -1, -1};
void push_(int ind, int val) {
	while (head[0] != tail[0] && Q[tail[0]][0].first > val)
		tail[0]--;
	Q[++tail[0]][0] = (make_pair(val, ind));
	while (head[1] != tail[1] && Q[tail[1]][1].first < val)
		tail[1]--;
	Q[++tail[1]][1] = (make_pair(val, ind));
}
void pop_(int ind) {
	while (head[0] != tail[0] && Q[head[0] + 1][0].second < ind)
		head[0]++;
	while (head[1] != tail[1] && Q[head[1] + 1][1].second < ind)
		head[1]++;

}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", s + i);
	for (int i = 0; i < k; i++) {
		push_(i, s[i]);
	}
	for (int i = k; i <= n; i++) {
		ans[i][0] = Q[head[0] + 1][0].first;
		ans[i][1] = Q[head[1] + 1][1].first;
		push_(i, s[i]);
		pop_(i - k + 1);
	}
	for (int j = 0; j < 2; j++, putchar(10))
		for (int i = k; i <= n; i++) {
			if (i - k)
				putchar(32);
			printf("%d", ans[i][j]);
		}
	return 0;
}