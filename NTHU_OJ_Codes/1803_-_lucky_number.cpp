#include<cstdio>

int main(){
	char s[4];
	while(scanf("%s", s) > 0){
		int x = s[0] + 2*s[1] + s[2] - 4 * '0';
		while(x >= 10)
			x = x/10+x%10;
		printf("%d\n", x);
	}
	return 0;
}
