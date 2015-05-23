#include<cstdio>
#include<cctype>

void print(char s[]){
	int fg = 0;
	for(int i = 0; s[i]; i++)
		if(isdigit(s[i])){
			if(s[i] != '0')
				fg = 1;
			if(fg)
				putchar(s[i]);
		}
	if(!fg)
		putchar('0');
}
int main(){
	int t;
	char s[1000];
	scanf("%d", &t);
	getchar();
	while(t--){
		gets(s);
		print(s);
		gets(s);
		putchar('/');
		gets(s);
		print(s);
		putchar(10);
		getchar();
	}
	return 0;
}
