#include<stdio.h>
#include<string.h>
char s[1001], t[1001], ans[1001][1001];
int main(){
	int x;
	scanf("%d", &x);
	while(x--){
		scanf("%s%s",s, t);
		int l1 = strlen(s), l2 = strlen(t), i, j, max = 0;
		for(i = 0; i < l1; i++)
			for(j = 0; j < l2; j++)
				if(s[i] == t[j])
					ans[i][j] = 1;
				else
					ans[i][j] = 0;
		for(i = 0; i < l1; i++)
			for(j = 0; j < l2; j++)
				if(ans[i][j]){
					int k = 0, ct = 0;
					while(i + k < l1 && j + k < l2 && ans[i + k][j + k])
						ct++, ans[i + k][j + k] = 0, k++;
					if(ct > max)
						max = ct;
				}
		printf("%d\n", max);
	}
	return 0;
}
