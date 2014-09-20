#include<stdio.h>
#include<string.h>
long long pre[1000000];
int s[1000000], rec[1000000];
void print(int a, int b) {
	printf("%d", a + 1);
	for (int i = a + 1; i <= b; i++)
		printf(" %d", i + 1);
	puts("");
}
int main() {
	int n, c;
	while (scanf("%d%d", &c, &n), n + c > 0) {
		memset(rec, -1, sizeof(rec));
		memset(pre, 0, sizeof(pre));
		for (int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		pre[0] = s[0];
		rec[pre[0] % c] = 0;
		if (pre[0] % c == 0) {
			puts("1");
			continue;
		}
		for (int i = 1; i < n; i++) {
			pre[i] = pre[i - 1] + s[i];
			if (pre[i] % c == 0) {
				print(0, i);
				break;
			}
			else if (rec[pre[i] % c] >= 0) {
				print(rec[pre[i] % c] + 1, i);
				break;
			}
			rec[pre[i] % c] = i;
		}
	}
	return 0;
}