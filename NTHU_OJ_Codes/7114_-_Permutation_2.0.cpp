#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	int t, ct = 0;
	long long ans, fact[30];
	char s[30], sorted[30];
	fact[0] = 1;
	for(int i = 1; i < 30; i++)
		fact[i] = fact[i-1]*i;
	scanf("%d", &t);
	getchar();
	while(t--){
		gets(s);
		strcpy(sorted, s);
		int len = strlen(s);
		sort(sorted, sorted+len);
		ans = 0;
		for(int i = 0; i < len; i++){
			int temp = 0;
			for(int j = 0; j < len; j++){
				if(sorted[j] == s[i]){
					sorted[j] = 0;
					break;
				}
				if(sorted[j]) temp++;
			}
			ans += temp * fact[len - 1 - i];
		}
		printf("Case #%d: %lld\n", ++ct, ans+1);
	}
	return 0;
}
