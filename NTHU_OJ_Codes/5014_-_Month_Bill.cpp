#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[1000000];
int main(){
	int ct = 0;
	while(gets(s) > 0){
		int i, tot = 0, l = strlen(s);
		for(i = 0; i < l; i++){
			char temp[100] = {0};
			int j = 0;
			while(s[i] >= '0' && s[i] <= '9')
				temp[j++] = s[i++];
			tot += atoi(temp);
		}
		printf("Day %d: %d\n", ++ct, tot);
	}
	return 0;
}
