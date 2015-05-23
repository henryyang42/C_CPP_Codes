#include<stdio.h>
#include<math.h>
#define N 46340
int main(){
	char s[N];
	int prime[N] = {0}, ct[N] = {0}, i, j, k, a, aa;
	for(i = 2, k = 0; i < N; i++)
		if(!s[i]){
			prime[k++] = i;
			for(j = i*2; j < N; j += i)
				s[j] = 1;
		}
	while(scanf("%d",&a) > 0){
		aa = a;
		i = 0, j = 0;
		while(a > 1 && i < k){
			while(a % prime[i] == 0)
				ct[i]++, a /= prime[i];
			i++;	
		}
		for(i = 0; i < N; i++)
			if(ct[i]){
				if(j)
					printf("*");
				printf("%d", prime[i]);
				if(ct[i] >= 1)
					printf("^%d",ct[i]);
				j++, ct[i] = 0;
			}
			if(a > 1)
				if(j)
					printf("*%d^1", a);
				else
					printf("%d^1", a);
			putchar('\n');
	}
    return 0;
}
