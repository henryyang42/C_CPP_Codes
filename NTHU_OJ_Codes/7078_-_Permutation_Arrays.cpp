#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
char str[100000][200];
int index[100000];

int main(){
	int t, i, ct = 0, n, x;
	scanf("%d", &t);
	getchar();
	while(t--){
		char s[100000] = {0};
		getchar();
		if(ct++)
			putchar(10);
		gets(s);
		for(i = 0, n = 0; s[i]; i++){
			char temp[10] = {0};
			int j = 0;
			while(isgraph(s[i]))
				temp[j++] = s[i++];
			index[atoi(temp) - 1] = n++;
		}
		gets(s);
		for(i = 0, x = 0; s[i]; i++){
			char temp[100] = {0};
			int j = 0;
			while(s[i] != ' ' && s[i] != 10 && s[i] != 0)
				temp[j++] = s[i++];
			strcpy(str[x++], temp);
		}
		for(i = 0; i < n; i++)
			puts(str[index[i]]);
	}
	return 0;
}
