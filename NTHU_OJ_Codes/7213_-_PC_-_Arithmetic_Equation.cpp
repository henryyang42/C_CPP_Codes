#include<stdio.h>
#include<stack>
#include<string.h>
#include<ctype.h>
using namespace std; 
int rank(char c){
	switch(c){
		case '(': return 0;
		case '+': case '-': return 1;
		case '*': case '/': return 2;	
	}	
}
int main(){
	stack<char> op;
	char s[10000] = {0};
	int t, l;
	scanf("%d", &t);
	getchar();
	while(t--){
		gets(s);
		l = strlen(s);
		for(int i = 0; i < l; i++){
			if(isdigit(s[i]))
				while(isdigit(s[i]))
					putchar(s[i++]);
			if(s[i] == ')')
				while(1){
					if(op.top() != '(')
						putchar(op.top());
					char c = op.top();
					op.pop();
					if(c == '(')
						break;
				}
			if(s[i] != ')' && s[i] != '(')
				while(!(op.empty() || (rank(op.top()) < rank(s[i]))))
					putchar(op.top()), op.pop();
			if(s[i] != ' ' && s[i] != ')' && s[i] != 32 && s[i] != 0)
					 op.push(s[i]);
		}
		while(!op.empty())
			putchar(op.top()), op.pop();
		putchar(10);
	}
	return 0;
}
