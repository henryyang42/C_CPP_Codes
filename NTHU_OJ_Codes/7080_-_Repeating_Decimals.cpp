#include<stdio.h>
#include<string.h>
int stack[30000], s[30000];
int main(){
	int a, b, top, ct = 0, i;
	while(scanf("%d%d", &a, &b) > 0){
		memset(s, 0, sizeof(s));
		printf("%d/%d = %d.",a, b, a / b);
		a %= b;
		a *= 10;
		top = 0;
		while(!s[a]){
			s[a] = 1;
			stack[top++] = a;
			a %= b;
			a *= 10;
		}
		for(i = 0; stack[i] != a; i++)
			putchar('0' + stack[i] / b);
		int start = i;
		putchar('(');
		for(; i < top && i < 50; i++)
			putchar('0' + stack[i] / b);
		if(i < top)
			puts("...)");
		else
			puts(")");
		printf("   %d = number of digits in repeating cycle\n", top - start);
		putchar(10);
	}
	return 0;
}
