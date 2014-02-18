#include<stdio.h>
#include<stdlib.h>
typedef struct dic{
	char leaf;
	Dic next[10];
}Dic;
int main(){
	char s[100];
	int n, t;
	scanf("%d", &t);
	while(t--){
		Dic root = null;
		int fg = 1;
		scanf("%d", &n);
		while(n--){
			if(n
		}
		puts(fg ? "YES" : "NO");
	}
	return 0;
}
