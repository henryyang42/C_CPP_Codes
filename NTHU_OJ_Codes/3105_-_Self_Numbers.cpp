#include<stdio.h>
char s[10001];

int d(int i){
	int x = i, digit = 0;
	while(x > 0)
		digit += x % 10, x /= 10;
	return i + digit;
}
int main(){
	int x = 0, i;
	while(++x < 10000)
		if(s[x] == 0){
			printf("%d\n", x);
			i = x;
			while(i < 10000){
				i = d(i);
				if(s[i] == 1) break;
				s[i] = 1;
			}
		}
	return 0;
}
