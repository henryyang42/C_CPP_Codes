#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char s[1000];
	while(gets(s) > 0){
		int i, j, k, l = strlen(s), tot = 0;
		for(i = 0; i < l; i++){
			while(isalpha(s[i]))
				i++;
			if(isupper(s[i - 1]) && i - 1 >= 0)
				tot ++;
		}
		printf("%d\n", tot);	
	}
	return 0;
}
