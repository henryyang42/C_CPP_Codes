#include<stdio.h>

int main() {
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c), a + b + c > 0) {
		long long ans = 0;
		for (int i = 0; i <= a - 8; i++, c = !c) {
			if (b - 8 - !c >= 0)
				ans += (b - 8 - !c) / 2 + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}