#include<stdio.h>
#include<string.h>
int fib[1200000];
int table[] = {3, 4, 7, 7, 13, 25, 49, 97, 193, 385, 769, 1537, 3073, 6145, 12289, 24577, 49153, 98305, 196609, 393217, 786433};
int main(){
	int n, M, i, m;
	memset(fib, 1, sizeof(fib));
	for(fib[0] = 0, fib[1] = 1, i = 2, m = 1 << 20; fib[i - 1] != 0; i++)
		fib[i] = fib[i - 1] + fib[i - 2], fib[i] %= m;/* printf("fib[%d] = %d\n", i, fib[i]);*/
	while(scanf("%d%d", &n, &M) > 0){
		i = table[20];
		printf("%d\n", fib[n % (i - 1)] % (1 << M));
	}
	return 0;
}
