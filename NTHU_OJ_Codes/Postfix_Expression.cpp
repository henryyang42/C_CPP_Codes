#include<stdio.h>
#include<stack>
#include<string.h>
#include<ctype.h>

int rank(char c){
	switch(c){
		case '(': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;
	}
}
char* in2post(char s[]){
	char ans[1000] = {0}, stack[1000];
	int ct = 0, top = -1, fg = 0;
	int l = strlen(s);
	for(int i = 0; i < l; i++){
		if(isdigit(s[i])){
			if(fg++)
				ans[ct++] = ' ';
			while(isdigit(s[i]))
				ans[ct++] = s[i++];
		}
		if(s[i] == '(')
			stack[++top] = s[i];
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			while(stack[top] >= s[i] && top >= 0){
				if(fg++)
					ans[ct++] = ' ';
				ans[ct++] = stack[top--];
			}
			stack[++top] = s[i];
		}
		if(s[i] == ')'){
			while(top >= 0 && stack[top] != '('){
				if(fg++)
					ans[ct++] = ' ';
				ans[ct++] = stack[top--];
			}
			top--;
		}
	}
	while(top >= 0){
		if(fg++)
			ans[ct++] = ' ';
		ans[ct++] = stack[top--];
	}
	ans[ct] = 0;
	return ans;

}
int main(){
	char s[1000] = {0};
	while(gets(s) > 0){
		puts(in2post(s));
	}
	return 0;
}
