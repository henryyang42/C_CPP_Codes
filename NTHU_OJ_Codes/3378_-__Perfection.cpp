#include<stdio.h>
int main(){
	int n;
	puts("PERFECTION OUTPUT");
	while(scanf("%d", &n), n){
		int x = 0;
		printf("%5d  ", n);
		for(int i = 1; i < n; i++)
			if(n % i == 0)
				x += i;
		if(x == n)
			puts("PERFECT");
		if(x < n)
			puts("DEFICIENT");
		if(x > n)
			puts("ABUNDANT");
	}
	puts("END OF OUTPUT");
	return 0;
}
