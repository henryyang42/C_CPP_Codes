#include<stdio.h>
int base(int a){
	char s[11];
	sprintf(s, "%d", a);
	int max = 0, i = 0, tot = 0;
	while(s[i])
		if(s[i] - 48 > max)
			max = s[i++] - 48;
		else
			i++;
	i = 0;
	max ++;
	while(s[i])
		tot = tot * max + s[i++] - 48;
	return tot;
}
int main(){
	int a, b, t;
	while(scanf("%d", &t) > 0)
		while(t--)
			scanf("%d%d", &a, &b), printf("%d\n", base(a) + base(b));
	return 0;
}
