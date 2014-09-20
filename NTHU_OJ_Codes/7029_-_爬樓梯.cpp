#include<stdio.h>

int main(){
	int t, n, k;
	scanf("%d", &t);
	while(t--){
		int dpL[1001] = {}, dpR[1001] = {};
		dpL[0] = 1, dpR[0] = 1;
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++){
			for(int j = 2; j <= 2*k && i - j >= 0; j+= 2)
				dpL[i] += dpR[i-j], dpL[i] %= 12345678;
			for(int j =1; j < 2*k && i - j >= 0; j+= 2)
				dpR[i] += dpL[i-j], dpR[i] %= 12345678;
		}
		printf("%d\n", (dpL[n] + dpR[n]) % 12345678);
	}
	return 0;
}
