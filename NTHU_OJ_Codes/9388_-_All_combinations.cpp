#include<stdio.h>
#include<set>
#include<algorithm>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
int main(){
	int ct, t, n, m, fact[17];
	char s[18], ss[2];
	fact[0] = 1;
	for(int i = 1; i <= 16; i++)
		fact[i] = fact[i-1] * i;
	scanf("%d", &t);
	for(int x = 1; x <= t; x++){
		scanf("%d%d", &n, &m);
		printf("Case %d:\n", x);
		for(int i = 0; i < n; i++)
			scanf("%s", ss), s[i] = ss[0];
		sort(s, s+n);
		int ct = 0;
		do{
				sort(s+m, s+n);
				reverse(s+m, s+n);
				char c = s[m];
				s[m] = 0;
				puts(s);
				s[m] = c;
		}while(next_permutation(s, s+n));
	}
	return 0;
}
