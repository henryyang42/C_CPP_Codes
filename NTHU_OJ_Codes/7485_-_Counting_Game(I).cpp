#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char s[1000];
	while(gets(s) > 0){
		int i, j, k, l = strlen(s), tot = 0;
		for(i = 0; i < l; i++){
			if(isupper(s[i]))
				tot ++;
			while(isalpha(s[i]))
				i++;
		}
		printf("%d\n", tot);	
	}
	return 0;
}
