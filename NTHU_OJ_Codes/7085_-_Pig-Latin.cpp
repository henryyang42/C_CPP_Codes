#include<stdio.h>
#include<ctype.h>
#include<string.h>
int isvowel(char c){
	char s[] = "AEIOUaeiou";
	int i = 0;
	while(i < 10)
		if(s[i++] == c)
			return 1;
	return 0;	
}
void print(char s[]){
	char *ss = s + 1;
	if(isvowel(s[0]))
		printf("%say", s);
	else
		printf("%s%cay", ss, s[0]);
}
char s[10000000], temp[10000000];
int main(){
	while(gets(s) > 0){
		int i, j, l = strlen(s);
		for(i = 0; i < l; i++){
			j = 0;
			if(isalpha(s[i])){
				while(isalpha(s[i]))
					temp[j++] = s[i++];
				temp[j] = 0;
				print(temp);
			}
			if(!isalpha(s[i]))
				putchar(s[i]);
		}
		putchar(10);
		memset(s, 0, sizeof(s));
	}
	return 0;
}
