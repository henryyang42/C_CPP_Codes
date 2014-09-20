#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAX 20
int fact[MAX];
void permutation(int s[], int n, int k){
	int ct[MAX] = {0}, order[MAX] = {0}, copy[MAX], i, j, l;
	memcpy(copy, s, sizeof(copy));
	for(i = 0; i < n; i++){
		j = k / fact[n - i - 1] + 1, k %= fact[n - i - 1];
		l = 0;
		while(j){
			if(ct[l] == 0)
				j--;
			if(j == 0)
				ct[l] = 1, order[i] = l;
			l++;
		}
	}
	for(i = 0; i < n; i++)
		s[i] = copy[order[i]];
}
int main(){
	int s[MAX], n, k, i;
	for(i = 1, fact[0] = 1; i < MAX; i++)
		fact[i] = fact[i - 1] * i;
	while(scanf("%d%d", &n, &k) > 0, n + k){
		for(i = 0; i < n; i++)
			scanf("%d", &s[i]);
		std::sort(s, s + n);
		permutation(s, n, fact[n] - k);
		for(i = 0; i < n; i++){
			if(i)
				putchar(32);
			printf("%d", s[i]);
		}
		putchar(10);
	}
	return 0;
}
