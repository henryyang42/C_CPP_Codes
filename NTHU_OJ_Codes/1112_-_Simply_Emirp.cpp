#include<string.h>
#include<stdio.h>
char prime[1000001] = {0}, temp;
int i, j, n, n_reverse;
int main(){
	for(i = 2 ,prime[0] = 1, prime[1] = 1; i <= 1000000; i++)
		if(!prime[i])
			for(j = i * 2; j <= 1000000; j += i)
				prime[j] = 1;
	while(scanf("%d" ,&n) > 0){
		char s[10] = {0};
		sprintf(s, "%d", n);
		for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
			temp = s[i], s[i] = s[j], s[j] = temp;
		sscanf(s, "%d", &n_reverse);
		if(!prime[n_reverse] && n != n_reverse)
			printf("%d is emirp.\n", n);
		else if(!prime[n])
			printf("%d is prime.\n", n);
		else
			printf("%d is not prime.\n", n);
	}
	return 0;
}
