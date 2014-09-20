#include<stdio.h>

int main(){
	int n, i, ct, j;
	while(scanf("%d", &n) > 0, n){
		int s[1500] = {0};
		s[0] = 1;
		
		for(i = n * 2; i > n + 1; i--){
			for(j = 0; j < 1500; j++)
				s[j] *= i;
			for(j = 0; j < 1500; j++)
				s[j+1] += s[j] / 10, s[j] %= 10;	
		}
		i = 1499;
		while(s[i] == 0)
			i--;
		while(i >= 0)
			putchar(s[i--] + '0');
		putchar(10);
	}
	return 0;
}
