#include<cstdio>
#include<cstring>

void recovery(char s[], char t[], int len){
	for(int i = 0; i < len; i++)
		if(s[0] == t[i]){
			recovery(s+1, t, i);
			recovery(s+i+1, t+i+1, len-i-1);
			putchar(s[0]);
			break;
		}
}
int main(){
	char s[100], t[100];
	while(scanf("%s%s", s, t) > 0){
		recovery(s, t, strlen(s));
		putchar(10);
	}
	return 0;
}
