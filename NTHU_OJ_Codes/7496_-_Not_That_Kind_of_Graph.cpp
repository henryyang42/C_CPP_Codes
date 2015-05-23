#include<stdio.h>
#include<string.h>
int main(){
	int t, ct = 0, i, j, k, l;
	const char C = '_', R = '/', F = '\\';
	while(scanf("%d", &t) > 0)
		while(t--){
			char map[101][101] = {0}, last, s[100] = {0};
			int y = 50, x = 0, max = 50, min = 50;
			scanf("%s", s);
			l = strlen(s);
			printf("Case #%d:\n", ++ct);
			for(i = 0; i < l; i++){
				if(s[i] == 'R')
					s[i] = '/';
				if(s[i] == 'C')
					s[i] = '_';
				if(s[i] == 'F')
					s[i] = '\\';
			}
			last = s[0], map[y][x] = last;
			for(i = 1; i < l; i++){
				if((last == R && s[i] == C) || (last == R && s[i] == R))
					map[++y][++x] = s[i];
				else if((last == C && s[i] == F) || (last == F && s[i] == F))
					map[--y][++x] = s[i];
				else
					map[y][++x] = s[i];
				if(max < y)
					max = y;
				if(min > y)
					min = y;
				last = s[i];	
			}
				for(j = max; j >= min; j--){
					putchar('|'), putchar(32);
					int last = 100;
					while(map[j][last] == 0 && last > 0)
						last--;
					for(k = 0; k <= last; k++)
						if(map[j][k])
							putchar(map[j][k]);
						else
							putchar(32);
						putchar(10);
				}
				putchar('+');
				l+=2;
				while(l--)
					putchar('-');
				putchar(10);putchar(10);
			}
		
	return 0;
}
