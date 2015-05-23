#include<cstdio>

int main(){
	int a, b;
	while(scanf("%d%d", &a, &b), a+b){
		int carry = 0, ct = 0;
		while(a || b){
			carry = (a%10 + b%10 + carry) / 10;
			ct += carry;
			a /= 10, b /= 10;
		}
		if(ct)
			printf("%d %s\n", ct, (ct>1)?"carry operations.":"carry operation.");
		else
			puts("No carry operation.");
	}
	return 0;
}
