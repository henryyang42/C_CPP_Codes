#include<stdio.h>
int gcd(int a, int b){
	while(a && b)
		if(a > b)
			a %= b;
		else b %= a;
	return a + b;
}

int main(){
	int a, int b;
	while(scanf("%d%d", &a, &b), a + b){

	}
}
