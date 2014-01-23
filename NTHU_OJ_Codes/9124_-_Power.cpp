#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 2000
void square(int s[]){
	int i, j, l = MAX / 2 - 1;
	int temp[MAX] = {0};
	for(i = 0; i < MAX / 2; i++)
		for(j = 0; j < MAX / 2; j++)
			temp[i + j] += s[i] * s[j];
	for(i = 0; i < MAX; i++)
		temp[i + 1] += temp[i] / 10, temp[i] %= 10;
	memcpy(s, temp, sizeof(temp));
}
void times(int s[], int num[]){
	int i, j, l = MAX / 2 - 1;
	int temp[MAX] = {0};
	for(i = 0; i < MAX / 2; i++)
		for(j = 0; j < MAX / 2; j++)
			temp[i + j] += s[i] * num[j];
	for(i = 0; i < MAX; i++)
		temp[i + 1] += temp[i] / 10, temp[i] %= 10;
	memcpy(s, temp, sizeof(int) * MAX);
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, i, j, a, l;
		int ans[MAX] = {0}, temp[MAX] = {0}, c;
		ans[0] = 1;
		scanf("%d%d", &a, &n);
		for(l = 0; a > 0; l++)
			temp[l] = a % 10, a /= 10;
		for(i = 0; n >> i; i++){
			if((n >> i) & 1)
				times(ans, temp);
			square(temp);		
		}
		i = MAX - 1;
		while(ans[i] == 0)
			i--;
		if(i < 0)
			puts("0");
		else{
			while(i >= 0)
				putchar('0' + ans[i--]);
			putchar(10);
			}
	}
	return 0;
}
