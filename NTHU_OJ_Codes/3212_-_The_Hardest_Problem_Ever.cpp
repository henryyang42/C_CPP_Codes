#include<stdio.h>
#include<string.h>
#include<ctype.h>
char key[] = "VWXYZABCDEFGHIJKLMNOPQRSTU", s[200];
int main(){
	while(gets(s) > 0){
		if(strcmp(s, "ENDOFINPUT") == 0)
			break;
		gets(s);
		for(int i = 0; s[i]; i++)
			if(isalpha(s[i]))
				putchar(key[s[i] - 'A']);
			else
				putchar(s[i]);
		putchar(10);
		gets(s);
	}
	return 0;
}
