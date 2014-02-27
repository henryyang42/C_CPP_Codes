#include<cstdio>

int main(){
	int t, ct, n, m;
	char s[500][500];
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		getchar();
		ct = 0;
		for(int i = 0; i <= 4*n; i++)
			gets(s[i]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(s[4*i+2][4*j+1] == '*' && s[4*i+2][4*j+2] == '*' && s[4*i+2][4*j+3] == ' ')
					ct++;
		printf("%d\n", ct);
	}
	return 0;
}
