#include<stdio.h>
int cola(int n, int isborrow){
	int temp, tot = n;
	while(n / 3 > 0){
		tot += temp = n / 3;
		n %= 3;
		n += temp;
	}
	if(n - isborrow < 0)
		return 0;
	return tot;
}
int max(int a, int b){
	return a > b ? a : b;
}
int main(){
	int n;
	while(scanf("%d", &n) > 0)
		printf("%d\n", max(cola(n, 0), max(cola(n+1, 1)-1, cola(n+2, 2)-2)));
	return 0;
}
