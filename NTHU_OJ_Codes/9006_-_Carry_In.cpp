#include<stdio.h>
#include<string.h>
#define N 200
char s1[N], s2[N], ans[N];
void reverse_add(char *p){
	int l = strlen(p), i;
	for(i = 0; i < l; i++)
		ans[i] += *(p + l - 1 - i) - '0';
}
int main(){
	int i, l, carry;
	while(scanf("%s%s",s1,s2)>0){
		memset(ans, 0, sizeof(ans));
		reverse_add(s1);
		reverse_add(s2);
		for(i = 0, carry = 0; i < N; i++)
			if(ans[i] >= 10)
				carry++, ans[i + 1] += ans[i] / 10, ans[i] %= 10;
		printf("%d\n",carry);
	}
    return 0;
}
