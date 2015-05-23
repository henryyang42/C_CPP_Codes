#include<stdio.h>
#include<ctype.h>
#include<string.h>

void print(char s[], int l){
	while(l >= 0)
		putchar(s[l--]);
}
char s[100000], temp[100000];
int main(){
	while(gets(s) > 0){
		int i, j, l = strlen(s);
		for(i = 0; i < l; i++){
			j = 0;
			while(s[i] != ' ' && s[i] != 10 && s[i] != 0)
				temp[j++] = s[i++];
			temp[j] = 0;
			print(temp, j - 1);
			if(s[i] == 32)
				putchar(s[i]);
		}
		putchar(10);
		memset(s, 0, sizeof(s));
	}
	return 0;
}
