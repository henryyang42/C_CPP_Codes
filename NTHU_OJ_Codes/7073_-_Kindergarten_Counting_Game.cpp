#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char s[1000];
	while(gets(s) > 0){
		int ct = 0, l = strlen(s), i;
		for(i = 0; i < l; i++){
			int j = 0;
			char temp[100] = {0};
			while(s[i] != 10 && s[i] != 32)
				temp[j++] = s[i++];
			if(isalpha(temp[0]))
				ct++;	
		}
		printf("%d\n", ct);
	}
	return 0;	
}
