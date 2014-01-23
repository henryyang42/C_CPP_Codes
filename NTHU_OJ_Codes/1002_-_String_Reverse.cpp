#include<stdio.h>
#include<string.h>
char s[1000000];
int largest_base(int x){
	int base = 0, temp = x, tot = 0, i;
	while(temp){
		if(temp % 10 > base)
			base = temp % 10;
		temp /= 10;	
	}
	char s[10] = {0};
	sprintf(s, "%d", x);
	for(i = 0; s[i]; i++)
		tot += tot*base + s[i] - 48;
	return tot;
}
int main(){
	int t;
	while(scanf("%d", &t) > 0)
		while(t--){
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%d\n", largest_base(a) + largest_base(b));
		}
	return 0;
}
