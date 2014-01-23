#include<stdio.h>
char s[100];
int main(){
	while(gets(s) > 0){
		for(int i = 0; s[i]; i++){
			int x = "01230120022455012623010202"[s[i] - 'A'] - '0';
			if(x && ((i && x != "01230120022455012623010202"[s[i-1] - 'A'] - '0') || i == 0))
				putchar(x + '0');
		}
			putchar(10);
	}
	return 0;
}

