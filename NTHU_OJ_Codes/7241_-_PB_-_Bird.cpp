#include<stdio.h>
#include<string.h>
int main(){
	char s[100];
	while(gets(s) > 0)
		if(strcmp(s, "http://img.com/Bird/001.gif") == 0)
			puts("A");
		else if(strcmp(s, "http://img.com/Bird/002.gif") == 0)
			puts("B");
		else if(strcmp(s, "http://img.com/Bird/012.gif") == 0)
			puts("C");
		else if(strcmp(s, "http://img.com/Bird/042.gif") == 0)
			puts("D");
		else if(strcmp(s, "http://img.com/Bird/016.gif") == 0)
			puts("E");
		else if(strcmp(s, "http://img.com/Bird/105.gif") == 0)
			puts("F");
		else if(strcmp(s, "http://img.com/Bird/036.gif") == 0)
			puts("G");
		else if(strcmp(s, "http://img.com/Bird/032.gif") == 0)
			puts("H");
	return 0;
}
