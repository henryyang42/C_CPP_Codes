#include<stdio.h>

int main(){
	double tot, x;
	int i;
	while(scanf("%lf", &x) > 0, x){
		for(i = 1, tot = 1.0 / 2; tot < x; i++)
			tot += 1.0 / (2.0 + i);
		printf("%d card(s)\n", i);
	}
	return 0;
}
