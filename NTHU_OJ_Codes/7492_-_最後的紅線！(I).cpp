#include<stdio.h>

int main(){
	int a, b;
	while(scanf("%d%d", &a, &b) > 0){
		while(a > 0 && b > 0)
			if(a > b)
				a %= b;
			else
				b %= a;
			printf("%d\n", a + b);	
	}
	return 0;
}
