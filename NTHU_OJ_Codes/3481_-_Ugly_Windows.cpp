#include<stdio.h>
char s[101][101], ans[257];
int n, m;
int find_(char c){
	int maxi = -1, mini = n, maxj = -1, minj = m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		if(s[i][j] == c){
			if(i > maxi) maxi = i;
			if(j > maxj) maxj = j;
			if(i < mini) mini = i;
			if(j < minj) minj = j;
		}
	if(maxi == -1 || maxi - mini < 2 || maxj - minj < 2)
		return 0;
	for(int i = mini; i <= maxi; i++)
		if(s[i][maxj] != c || s[i][minj] != c)
			return 0;
	for(int j = minj; j <= maxj; j++)
		if(s[maxi][j] != c || s[mini][j] != c)
			return 0;
	for(int i = mini+1; i <= maxi-1; i++)
		for(int j = minj+1; j <= maxj-1; j++)
			if(s[i][j] != '.')
				return 0;
	return 1;
}
int main(){
    while(scanf("%d%d", &n, &m), m + n){
        for(int i = 0; i < 256; i++)
            ans[i] = 0;
        for(int i = 0; i < n; i++)
            scanf("%s", s[i]);
		for(int i = 'A'; i <= 'Z'; i++)
       		ans[i] = find_(i);
		for(int i = 'A'; i <= 'Z'; i++)
            if(ans[i])
                putchar(i);
        putchar(10);

    }
    return 0;
}
