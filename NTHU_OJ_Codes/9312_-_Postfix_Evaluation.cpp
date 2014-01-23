#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double postfix_eval(char s[]){
		double stack[10000];
		int i, j, k, l = strlen(s), now = 0, flag = 1;
		for(i = 0; i < strlen(s); i++){
			if(s[i] == ' ')
				continue;
			else if(s[i] >='0' && s[i] <= '9'){
				int r = 0;
				while(s[i] >='0' && s[i] <= '9')
					r = r*10 + s[i++] - '0';
				stack[now++] = r;
			}
			else{
				if(now < 2){

					break;
				}
				switch(s[i]){
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
						if(stack[now - 1] == 0){

							break;
						}
						stack[now - 2] = stack[now - 2] / stack[now - 1];
						now--;
						break;
				}
			}
		}
		return stack[0];
	}
int main(){
	char s[100000];

	while(gets(s) > 0)
		printf("%lf\n", postfix_eval(s));
	return 0;
}
