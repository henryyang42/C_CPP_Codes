#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){
	int n, l;
	char s[100];
	scanf("%d", &n);
	getchar();
	while(n--){
		gets(s);
		l = strlen(s);
		sort(s, s + l);
		do{
			puts(s);
		}while(next_permutation(s, s + l));
		putchar(10);
	}
	return 0;
}
