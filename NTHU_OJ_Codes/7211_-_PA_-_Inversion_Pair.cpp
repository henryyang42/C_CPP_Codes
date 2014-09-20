#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char str[100000];
	int s[1001];
	int i, j, a;
	while(gets(str) > 0){
		int ans = 0, l = strlen(str);
		for(i = 0, a = 0; i < l; i++){
			char temp[12] = {0};
			j = 0;
			while(isdigit(str[i]) || str[i] == '-')
				temp[j++] = str[i++];
			s[a++] = atoi(temp);	
		}
		for(i = 0; i < a; i++)
			for(j = i; j < a; j++)
				if(s[i]>s[j])
			ans++;
		printf("%d\n",ans);
	}
	return 0;
}
