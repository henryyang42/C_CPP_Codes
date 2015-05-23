#include<stdio.h>

int main(){
	int i, n, ct = 0, j, flag;
	char s[10];
	while(scanf("%d", &n) > 0){
		if(ct++)
			putchar(10);
		putchar('1');
		for(i = 2; i < n; i++){
			if(i % 3 != 0 && i % 7 != 0){
				sprintf(s, "%d", i);
				for(j = 0, flag = 0; s[j]; j++)
					if(s[j] == '3' || s[j] == '7')
						flag = 1;
				if(!flag)
					printf(" %d", i);	
			}	
		}
		putchar(10);
	}
	return 0;
}
