#include<stdio.h>
int main(){
	int a, b;
	while(scanf("%d%d", &a, &b) > 0){
		printf("[%d;", a / b);
		a -= b * (a / b);
		int ct = 0;
		while(a % b != 0){
			int temp = a;
			a = b, b = temp;
			if(ct)
				printf(",%d", a / b);
			else
				printf("%d", a / b);
			a -= b * (a / b);
			ct++;
		}
		if(ct)
			printf("]\n");
		else
			printf("0]\n");
	}
	return 0;
}
