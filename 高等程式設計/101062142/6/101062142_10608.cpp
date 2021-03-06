#include<stdio.h>
#define MAX 100000
int leader[MAX], ct[MAX];
int find(int x){
	int temp;
	while(x != leader[x])
		temp = x, leader[temp] = x = leader[x];
	return x;
}
int main(){
	int n, q, i, a, b, ans, temp, casect = 0, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &q);
		for(i = 0; i <= n; i++)
			leader[i] = i, ct[i] = 0;
		for(i = 0, ans = n; i < q; i++){
			scanf("%d %d", &a, &b);
			if(a > b)
				a = a ^ b, b = a ^ b, a = a ^ b;
			int fa = find(a), fb = find(b);
			if(fa != fb)
				leader[fb] = fa;
		}
		for(ans = 0, i = 1; i <= n; i++)
			ct[temp = find(i)]++, ans = ans > ct[temp] ? ans : ct[temp];
		printf("%d\n", ans);
	}
	return 0;
}
