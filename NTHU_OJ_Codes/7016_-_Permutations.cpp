#include<stdio.h>
#include<string.h>
#include<algorithm>
int main(){
	long long int n, fact[30], t;
	char s[100];
	fact[0] = 1;
	for(int i = 1; i < 30; i++)
		fact[i] = fact[i-1] * i;
	scanf("%lld", &t);
	while(t--){
		scanf("%s%lld", s, &n);
		int l = strlen(s);
		std::sort(s, s + l);
		for(int i = l - 1; i >= 0; i--){
			int k = (n / fact[i]) + 1;
			n %= fact[i];
			for(int i = 0; i < l; i++){
				if(s[i])
					k--;
				if(k == 0){
					putchar(s[i]);
					s[i] = 0;
					break;
				}
			}
		}
		putchar(10);
	}
	return 0;
}
