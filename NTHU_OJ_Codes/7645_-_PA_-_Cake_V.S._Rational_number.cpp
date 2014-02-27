#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		char s1[100], s2[100];
		scanf("%s%s", s1, s2);
		int l1 = strlen(s1), l2 = strlen(s2);
		int sp = max(l1, l2);
		for(int i = 0; i < (sp-l1)/2; i++)
			putchar(32);
		puts(s1);
		for(int i = 0; i < sp; i++)
			putchar('-');
		putchar(10);
		for(int i = 0; i < (sp-l2)/2; i++)
			putchar(32);
		puts(s2);
		putchar(10);
	}
	return 0;
}
