#include<stdio.h>
#include<string.h>
int main(){
	int t;
	scanf("%d", &t);
	getchar();
	while(t--){
		int l, top, ans[100][2] = {0}, i;
		char s[1000] = {0};
		gets(s);
		gets(s);
		l = strlen(s);
		for(i = 0; i < l; i += 6){
			s[i + 5] = 0;
			if(strcmp(s + i, "    @") == 0)
				ans[i / 6][0] = 1;
			if(strcmp(s + i, "@   @") == 0)
				ans[i / 6][0] = 2;	
			if(strcmp(s + i, "@    ") == 0)
				ans[i / 6][0] = 3;	
		}
		gets(s);
		gets(s);
		for(i = 0; i < l; i += 6){
			s[i + 5] = 0;
			if(strcmp(s + i, "    @") == 0)
				ans[i / 6][1] = 1;
			if(strcmp(s + i, "@   @") == 0)
				ans[i / 6][1] = 2;	
			if(strcmp(s + i, "@    ") == 0)
				ans[i / 6][1] = 3;	
		}
		gets(s);
		gets(s);
		for(i = 0; i < (l + 1) / 6; i++){
			if(i)
				putchar(32);
			if(ans[i][0] == 1 && ans[i][1] == 3)
				putchar('2');	
			if(ans[i][0] == 3 && ans[i][1] == 1)
				putchar('5');
			if(ans[i][0] == 3 && ans[i][1] == 2)
				putchar('6');
			if(ans[i][0] == 2 && ans[i][1] == 1)
				putchar('9');
		}
		putchar(10);
		if(strcmp(s, "") == 0)
			t++;
		if(strcmp(s, "*") == 0)
			putchar(10);
	}
	return 0;
}
