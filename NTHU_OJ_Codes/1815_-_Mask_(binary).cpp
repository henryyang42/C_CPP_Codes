#include<stdio.h>

int main(){
	char s[100];
	int ct = 0, len;
	while(scanf("%s", s) > 0){
		printf("CASE %d:\n", ++ct);
		len = 0;
		for(int i = 0; s[i]; i++)
			if(s[i] != '*')
				len++;
		for(int i = 0; i < 1 << len; i++){
			int fg = 0;
			for(int k = 0; s[k]; k++)
				if(s[k] == '*')
				putchar('*');
			else
				putchar('0' + ((i >>(len  - (++fg))) & 1));
			putchar(10);
		}
	}
	return 0;
}
