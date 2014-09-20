#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define N 200000
int a, b, i, q, aa, bb, max;
int g[N + 1], ct[N + 1];
void uni(int p1, int p2){
	if(g[p1] != g[p2]){
		int max = g[p1]>g[p2]?g[p1]:g[p2];
		int min = g[p1]<g[p2]?g[p1]:g[p2];
		int ii;
		for( ii = 1; ii <=a; ii++)
			if(g[ii] == max)
				g[ii] = min;
	}
}

int main(){
	while(scanf("%d",&a)>0, a){
		memset(ct, 0, sizeof(ct));
		for( i = 0; i <= a; i++)
			g[i] = i;
		scanf("%d", &b);
		for( i = 0; i < b; i++)
			scanf("%d%d",&aa,&bb), uni(aa > bb ? aa : bb,bb > aa ? aa : bb);
		for(i = 0; i <= a; i++)
			ct[g[i]]++;
		for(i = 0, max = 0; i <= a; i++)
			if(max < ct[i])
				max = ct[i];
		printf("%d\n", max);
	}
	return 0;
}
