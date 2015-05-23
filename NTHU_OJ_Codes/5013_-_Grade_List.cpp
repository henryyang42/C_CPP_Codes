#include<stdio.h>
#include<stdlib.h>
int main(){
	int ct = 0, i, a, b;
	char s[1001];
	while(gets(s) > 0){
		sscanf(s, "%d%d", &a, &b);
		printf("Student #%d: %d\n", ++ct, a + b);
	}
	return 0;
}
