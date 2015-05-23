#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int stack[100] = {0};
int main(){
	char c, temp[13];
	int n, ct, num, j, flag, isnode;
	while(scanf("%d", &n) > 0){
		ct = isnode = 1;
		flag = j = 0;
		while(getchar() != '(');
		while(ct){
			c = getchar();
			if(c == '('){
				if(j){
					isnode = 0;
					temp[j] = 0;
					num = atoi(temp);
					stack[ct] = stack[ct - 1] + num;
				}
				if(isnode == 0 || isnode == 2)
					isnode++;
				else
					isnode = 1;
				ct++;
				j = 0;
			}
			if(c == ')'){
				if(isnode == 1 || isnode == 3)
					isnode++;
				else
					isnode = 0;
				ct--;
				j = 0;
				if(isnode == 4)
					isnode = 0, flag += stack[ct] == n;
			}
			if(c == '-' || isdigit(c))
				temp[j++] = c;
		}
		if(flag)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
