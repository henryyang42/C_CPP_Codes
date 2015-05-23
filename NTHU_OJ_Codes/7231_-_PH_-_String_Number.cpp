#include<stdio.h>
#include<string.h>
char s[10000], c;
int ct[1001] = {0}, table[1001][1001] = {0};
int main(){
	int i, j;
	ct[0] = 1;
	table[0][0] = 1;
	for(i = 1; i < 1001; i++){
		for(j = 0; j < ct[i - 1]; j++)
			table[i][j] = table[i - 1][j] * 26;
		for(j = 0; j <= ct[i - 1] + 10; j++)
			table[i][j + 1] += table[i][j] / 10, table[i][j] %= 10;
		j = ct[i - 1] + 10;
		ct[i] = 1000;
	}
	while(scanf("%s", s) > 0){
		int ans[10000] = {0}, i, j, l;
		for(i = 0,l = j = strlen(s), j--; i < j; i++, j--)
			c = s[i], s[i] = s[j], s[j] = c;
		for(i = 0; i < l; i++){
			int k;
			for(k = 0; k < 26; k++)
				if(s[i] == "abcdefghijklmnopqrstuvwxyz"[k])
					break;
			for(j = 0; j < ct[i]; j++)
				ans[j] += table[i][j] * k;	
		}
		for(i = 0; i < 10000; i++)
			ans[i + 1] += ans[i] / 10, ans[i] %= 10;
		i = 9999;
		while(ans[i] == 0)
			i--;
		if(i < 0)
			puts("0");
		else{
			while(i >= 0)
				putchar('0' + ans[i--]);
			putchar(10);
		}
		memset(s, 0, sizeof(s));
	}
	return 0;
}
