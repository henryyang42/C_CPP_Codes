#include<stdio.h>
#include<string.h>
char s[1000001];
int find_(int n){
	for(int i = 1; i < n; i++)
		if(n % i == 0){
			int fg = 0;
			for(int j = 0; !fg && j < i; j++)
				for(int k = j; k < n; k += i)
					fg += !(s[j] == s[k]);
			if(fg == 0)
				return n / i;
		}
	return 0;
}
int main(){
	int n, ct = 0, k;
	while(scanf("%d", &n), n){
		scanf("%s", s);
		printf("Test case #%d\n", ++ct);
		for(int i = 2; i <= n; i++)
			if(k = find_(i))
				printf("%d %d\n", i, k);
		putchar(10);
	}
	return 0;
}
