#include<stdio.h>
int main(){
	int i, n, x;
	while(scanf("%d", &n) > 0){
		int ct[50002] = {0};
		int indexs[50002] = {0}, indexb[50002] = {0};
		int min = 2147483647;
		while(n--)
			scanf("%d", &x), ct[x]++;
		for(i = 1; i < 50001; i++)
			indexs[i] = indexs[i - 1] + ct[i];
		for(i = 50000; i > 0; i--)
			indexb[i] = indexb[i + 1] + ct[i];
		for(i = 1; i <= 25000; i++)
			min = min < indexb[2*i+1] + indexs[i-1] ? min : indexb[2*i+1] + indexs[i-1];
		printf("%d\n", min);
	}
	return 0;
}
