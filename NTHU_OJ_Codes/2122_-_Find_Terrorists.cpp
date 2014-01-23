#include<stdio.h>
char prime[10001];
int ans[10001];
int main(){
	int i, j, a, b, t, tot;
	for(prime[0] = 1, prime[1] = 1, i = 2; i < 10001; i++)
		if(prime[i] == 0)
			for(j = i * 2; j < 10001; j += i)
				prime[j] = 1;
	for(i = 2; i < 10001; i++){
		tot = 0;
		if(prime[i])
			for(j = 2; j < i; j++){
				a = i;
				while(a % j == 0)
					a /= j, tot++;
				if(tot)
					break;	
			}
		if(!prime[tot] && a == 1)
			ans[i] = 1;		
	}
	scanf("%d", &t);
	while(t--){
		tot = 0;
		scanf("%d%d", &a, &b);
		if(a > b)
			i = a, a = b, b = i;
		for(i = a; i <= b; i++)
			if(!prime[i] || ans[i])
				if(tot++)
					printf(" %d", i);
				else
					printf("%d", i);
			if(tot)
				putchar(10);
			else
				puts("-1");
	}
	return 0;
}
