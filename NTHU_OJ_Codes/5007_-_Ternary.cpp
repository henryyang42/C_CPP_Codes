#include<stdio.h>

int main(){
	int t;
	while(scanf("%d", &t) > 0){
		if(t == -1)
			return 0;
		int i = 0;
		char s[100] = {0};
		while(t > 0)
			s[i++] = t % 3, t /= 3;
		while(i > 0)
			putchar(s[--i] + '0');
		putchar(10);
	}
	return 0;
}
