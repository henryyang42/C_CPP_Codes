#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;
int list[10000][10], ct[10000];
void shift(char s[]){
	int i, l = strlen(s);
	char temp = s[0];
	for(i = 0; i < l; i++)
		s[i] = s[i + 1];
	s[l - 1] = temp;
}
int main(){
	int j, i, t, a, b, fg = 0;
	for(i = 1; i < 3100; i++){
		char s[10];
		sprintf(s, "%d", i);
		int l = strlen(s) - 1;
		map<int, int> m;
		while(l--){
			shift(s);
			int x = atoi(s);
			if(x > i && s[0] != '0' && !m[x])
				list[i][ct[i]++] = x, m[x] = 1;
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		int ans = 0;
		for(i = a; i < b; i++)
			for(j = 0; j < ct[i]; j++)
				if(list[i][j] <= b && list[i][j] >= a)
					ans++;
		printf("Case #%d: %d\n", ++fg, ans);
	}
	return 0;
}
