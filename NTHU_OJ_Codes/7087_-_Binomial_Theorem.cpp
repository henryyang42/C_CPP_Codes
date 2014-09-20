#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long int pas[1001][1001] = {0};
int main(){
	int i, j, n, ct = 0, m;
	pas[1][0] = 1, pas[1][1] = 1;
	for(i = 1; i < 1001; i++)
		pas[i][0] = 1;
	for(i = 2; i < 1001; i++)
		for(j = 1; j <= i; j++)
			pas[i][j] = (pas[i-1][j] + pas[i-1][j-1]);
	char s[1000], s1[100], s2[100], num[4];
	while(scanf("%d",&n)>0)
		while(n--){
			ct++;
			scanf("%s",s);
			i = 1, j = 0;
			while(s[i] != '+')
				s1[j++] = s[i++];
			s1[j] = 0;
			j = 0,i++;
			while(s[i] != ')')
				s2[j++] = s[i++];
			s2[j] = 0;
			i+=2,j = 0;
			while(s[i])
				num[j++] = s[i++];
			num[j] = 0;
			printf("Case %d: ",ct);
			for(i = 0, m = atoi(num); i <= m; i++){
				int co_f = m - i, co_b = i;
				if(pas[m][i]>1)
					printf("+%lld*",pas[m][i]);
				if(co_b == 0){
					if(co_f == 1)
						printf("%s",s1);
					else
						printf("%s^%d",s1,co_f);
				}
				else if(co_f == 0){
					if(co_b == 1)
						printf("+%s",s2);
					else
						printf("+%s^%d",s2,co_b);
				}
				else{
					printf("%s",s1);
					if(co_f > 1)
						printf("^%d",co_f);
					putchar('*');
					printf("%s",s2);
					if(co_b > 1)
						printf("^%d",co_b);
				}
			}
			putchar('\n');
		}
    return 0;
}
