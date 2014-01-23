#include<stdio.h>
#define MAX 10000000
char s[MAX + 1] = {0};
int prime[664579 + 1];
int main(){
	long long int Q, P;
	int i, j, ct = 0;
	for(i = 2; i < MAX; i++)
		if(s[i] == 0){
			prime[ct++] = i;
			for(j = i * 2; j < MAX; j += i)
				s[j] = 1;
		}
	while(scanf("%lld", &Q) > 0, Q){
		P = 2;
		while(Q % 2 == 0)
			Q /= 2;
		i = 0;
		while(Q >= prime[i] * prime[i] && i < ct){
			if(Q % prime[i] == 0){
				int temp = 0;
				while(Q % prime[i] == 0)
					temp++, Q /= prime[i];
				P *= 2 * temp + 1;	
			}
			i++;
		}
		if(Q > 1)
			P *= 3;
		printf("%lld\n", P);
	}
	return 0;
}
