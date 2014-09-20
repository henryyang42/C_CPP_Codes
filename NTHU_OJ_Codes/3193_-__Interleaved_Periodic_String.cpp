#include<stdio.h>

int main(){
	int t;
	char s[100];
	scanf("%d", &t);
	while(t--){
		int ct[2] = {};
		scanf("%s", s);
		for(int i = 0; s[i]; i++)
			ct[s[i] - '0']++;
		if(ct[0] && ct[1])
			puts("2");
		else
			puts("1");
	}
	return 0;
}
