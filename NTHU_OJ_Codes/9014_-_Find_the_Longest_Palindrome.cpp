#include<stdio.h>
#include<string.h>
char s[10001];
int main(){
	while(gets(s) > 0){
		int temp, len = 0, pos, l = strlen(s);
		for(int i = 0; i < l; i++){
			int j;
			//middle
			for(j = 1, temp = 0;i-j>= 0 && i+j<l && s[i+j] == s[i-j]; j++, temp++);
			if(temp*2+1 > len)
				pos = i, len = temp*2+1;
			//both side
			for(j = 1, temp = 0;i-j+1>= 0 && i+j<l && s[i+j] == s[i-j+1]; j++, temp++);
			if(temp*2 > len)
				pos = i, len = temp*2;
		}
		if(len % 2)
			for(int i = pos - (len-1) / 2; i <= pos + (len-1) / 2; i++)
				putchar(s[i]);
		else
			for(int i = pos - len / 2+1; i <= pos + len / 2; i++)
				putchar(s[i]);
		putchar(10);
	}
	return 0;
}
