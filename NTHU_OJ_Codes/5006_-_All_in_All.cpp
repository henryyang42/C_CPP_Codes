#include<stdio.h>
#include<string.h>
char s[100001], t[100001];
int main(){
	int i, j, lt, ls, tot = 0;
	while(scanf("%s%s", s, t) > 0){
		ls = strlen(s), tot = 0, lt = strlen(t);
		for(i = 0, j = 0; i < ls && j < lt; i++){
			while(t[j] != s[i] && j < lt)
				j++;
			if(s[i] == t[j])
				tot++, j++;
		}
		if(tot == ls)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
