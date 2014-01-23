#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[11000000];
struct data{
	int A, T, G, C;
}ans;
int main(){
	int n, l, i, j, k, unsortness;
	while(scanf("%s", s) > 0){
		l = strlen(s);
		unsortness = 0;
		ans.A = 0, ans.C = 0, ans.G = 0, ans.T = 0;
		for(i = l - 1; i >= 0; i--){
			/*printf("%d %d %d %d\n", ans.A, ans.T, ans.G, ans.C);*/
			if(s[i] == 'C')
				unsortness += ans.A;
			else if(s[i] == 'G')
				unsortness += ans.C + ans.A;
			else if(s[i] == 'T')
				unsortness += ans.C + ans.A + ans.G;
			if(s[i] == 'A')
				ans.A = ans.A + 1;
			if(s[i] == 'T')
				ans.T = ans.T + 1;	
			if(s[i] == 'G')
				ans.G = ans.G + 1;	
			if(s[i] == 'C')
				ans.C = ans.C + 1;
		}	
		printf("%d\n", unsortness);
	}
	return 0;
}
