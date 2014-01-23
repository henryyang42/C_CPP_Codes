#include<stdio.h>

int main(){
	int t, i;
	while(scanf("%d", &t) > 0){
		getchar();
		while(t--){
			char s[1290] = {0}, stack[1290] = {0};
			int start = 0;
			gets(s);
			for(i = 0; s[i]; i++){
				if(s[i] == ')' && start > 0 && stack[start - 1] == '(')
					start--;
				else if(s[i] == ']' && start > 0 && stack[start - 1] == '[')
					start--;
				else if(s[i] == '[' || s[i] == '(' || s[i] == ']' || s[i] == ')')
					stack[start++] = s[i];
			}
			if(start == 0)
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}
