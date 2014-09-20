#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 46360
int prime[MAX], s[MAX], pct, test[1000010];
int isprime(int x){
	if(x < MAX)
		return !s[x];
	int sqrt_x = sqrt(x);
	for(int i = 0; sqrt_x >= prime[i]; i++)
		if(x % prime[i] == 0)
			return 0;
	return 1;
}
int main(){
	s[0] = s[1] = 1;
	for(int i = 2; i < MAX; i++)
		if(!s[i]){
			prime[pct++] = i;
			for(int j = i + i; j < MAX; j += i)
				s[j] = 1;
		}
	int a, b;
	while(scanf("%d%d", &a, &b) > 0){
		int dis, last = 0, max, min, maxd = 0, mind = 2147483647;
		memset(test, 0, sizeof(test));
		for(unsigned int i = a; i <= b; i++)
			if(!test[i-a] && isprime(i)){
				if(last){
					dis = i - last;
					if(dis > maxd)
						maxd = dis, max = last;
					if(dis < mind)
						mind = dis, min = last;
				}
				last = i;
				for(unsigned int j = i+i; j <= b; j += i)
					test[j-a] = 1;
		}
		if(maxd)
			printf("%d,%d are closest, %d,%d are most distant.\n", min, min + mind, max, max + maxd);
		else
			puts("There are no adjacent primes.");
	}
	return 0;
}
