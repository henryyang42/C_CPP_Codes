#include<cstring>
#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;
char s[100], t[100];
void check(char d[], char str[]){
	int len = strlen(str);
	for(int i = 0; i < len; i++)
		if(isdigit(str[i]))
			d[i/4] = str[i];
}
long long toLL(char s[]){
	int len = strlen(s);
	long long x = 0;
	for(int i = 0; i < len; i++)
		x = x*10 + s[i]-'0';
	return x;
}
void print(long long x){
	char str[100];
	sprintf(str, "%lld", x);
	int len = strlen(str);
	for(int i = 0; i < len; i++) printf("+---"); puts("+");
	for(int i = 0; i < len; i++) printf("|   "); puts("|");
	for(int i = 0; i < len; i++) printf("| %c ", str[i]); puts("|");
	for(int i = 0; i < len; i++) printf("|   "); puts("|");
	for(int i = 0; i < len; i++) printf("+---"); puts("+");
}
int main(){
	int ct = 0;
	while(gets(s) > 0){
		char ds[100] = {}, dt[100] = {};
		check(ds, s);
		for(int i = 1; i < 5; i++)
			gets(s), check(ds, s);
		for(int i = 0; i < 5; i++)
			gets(t), check(dt, t);
		long long ans = __gcd(toLL(ds), toLL(dt));
		if(ct++)
			putchar(10);
		print(ans);
	}
	return 0;
}