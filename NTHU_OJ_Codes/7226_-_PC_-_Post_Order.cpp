#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	char s[100000];
	int t;
	int stack[10000];
	scanf("%d", &t);
	getchar();
	while(t--){
		gets(s);
		int i, j, k, l = strlen(s), now = 0;
		for(i = 0; i < strlen(s); i++){
			if(s[i] == ' ')
				continue;
			char temp[12] = {0};
			j = 0;
			while(s[i] != ' ' && s[i] != 0)
				temp[j++] = s[i++];
			if(isdigit(temp[0]) || strlen(temp) > 1)
				stack[now++] = atoi(temp);
			else{
				switch(temp[0]){
					case '+':
						stack[now - 2] = stack[now - 1] + stack[now - 2];
						now--;
						break;
					case '-':
						stack[now - 2] = stack[now - 2] - stack[now - 1];
						now--;
						break;	
					case '*':
						stack[now - 2] = stack[now - 1] * stack[now - 2];
						now--;
						break;	
					case '/':
						stack[now - 2] = stack[now - 2] / stack[now - 1];
						now--;
						break;	
					case '%':
						stack[now - 2] = stack[now - 2] % stack[now - 1];
						now--;
						break;		
				}	
			}	
		}
		printf("%d\n",stack[now-1]);
	}
	return 0;
}
