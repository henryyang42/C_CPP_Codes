#include<cstdio>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		long long tot = 0, tot2 = 0, x, mid, r;
		scanf("%lld", &r);
		for(int i = 0; i < r; i++)
			scanf("%lld", &x), tot += x, tot2 += x*x;
		mid = (double)tot/r + 0.5;
		printf("%lld\n", r*mid*mid-2*tot*mid+tot2);
	}
	return 0;
}
