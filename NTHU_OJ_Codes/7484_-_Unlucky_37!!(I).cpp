#include<stdio.h>
int s[10001];
int main(){
	for(int i = 0; i < 10001; i++)
		if(i % 3 != 0 && i % 7 != 0)
			s[i] = 1;
		else
			s[i] = 0;
	int n, ct = 0;
	while(scanf("%d", &n) > 0){
		int tag = 0;
		if(ct++)
			putchar(10);
		for(int i = 1; i < n; i++)
			if(s[i])
				if(tag++)
					printf(" %d", i);
				else
					printf("%d", i);
		putchar(10);
	}
	return 0;
}
