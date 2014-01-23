#include<stdio.h>
int s[10001];
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, q, i, temp, a, b;
		scanf("%d%d", &n, &q);
		for(s[0] = 0, i = 1; i <= n; i++)
			scanf("%d", &temp), s[i] = s[i - 1] + temp;
		for(i = 0; i < q; i++)
			scanf("%d%d", &a, &b), printf("%d\n", s[b] - s[a - 1]);
	}
	return 0;	
}
