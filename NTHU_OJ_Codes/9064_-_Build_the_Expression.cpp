#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int s[100];
int n, ansct;
long long int operand[100];
char oper[100];
void dfs(int level, int ct, int op){
	int i;
	if(n == level){
		long long ans = operand[0];
		for(i = 0; i < op; i++)
			ans += (oper[i] == '+' ? 1 : -1) * operand[i+1];
		if(ans==0)
			ansct++;
		return;	
	}
	for(i = 0; i < 3; i++)
		switch(i){
			case 0:
				oper[op] = '+';
				operand[ct] = s[level];
				dfs(level+1, ct+1, op+1);
				break;
			case 1:
				oper[op] = '-';
				operand[ct] = s[level];
				dfs(level+1, ct+1, op+1);
				break;
			case 2:
				operand[ct-1] = operand[ct-1] * 10 + s[level];
				dfs(level+1, ct, op);
				break;	
		}
}
int main(){
	int casect = 0;
	while(scanf("%d", &n) > 0, n){
		int i;
		for(i = 0, ansct = 0; i < n; i++)
			scanf("%d", &s[i]);
		operand[0] = s[0];
		dfs(1, 1, 0);
		printf("Case %d: %d\n", ++casect, ansct);
	}
	return 0;
}
