#include<stdio.h>
#include<string.h>
#define MAX 200
void mul(int s[], int x){
	for(int i = 0; i < MAX; i++)
		s[i] *= x;
	for(int i = 0; i < MAX - 1; i++)
		s[i+1] += s[i] / 10, s[i] %= 10;
}
void add(int ans[], int s[]){
	for(int i = 0; i < MAX; i++)
		ans[i] += s[i];
	for(int i = 0; i < MAX - 1; i++)
		ans[i+1] += ans[i] / 10, ans[i] %= 10;
}
int main(){
	int n, a, i, fg;
	while(scanf("%d%d", &n, &a) > 0){
		int ans[MAX] = {0}, s[MAX] = {0}, temp[MAX] = {0};
		s[0] = 1;
		for(i = 1; i <= n; i++){
			mul(s, a);
			memcpy(temp, s, sizeof(s));
			mul(temp, i);
			add(ans, temp);
		}
		for(i = MAX - 1, fg = 0; i >= 0; i--){
			fg += ans[i];
			if(fg)
				putchar('0' + ans[i]);
		}
		if(fg == 0)
			putchar('0');
		putchar(10);
	}
	return 0;
}
