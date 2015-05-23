#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str{
	char race[8];
	int property[4];
}S;

S in[500];
char s[4][8] = {"ID", "HP", "ATK", "REC"};
int img[4];

int cmp(const void *a, const void *b){
	S *c = (S *) a, *d = (S *) b;
	if(strcmp(c -> race, d -> race))
		return strcmp(c -> race, d -> race);
	int i;
	for(i = 0; i < 4; i++)
		if(d -> property[img[i]] - c -> property[img[i]])
			return d -> property[img[i]] - c -> property[img[i]];
	return 0;
}

int main(){
	int t, n, i, j, tc = 0;
	char race[8], priority[4][8];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%s %d %d %d %d", in[i].race, &in[i].property[0], &in[i].property[1], &in[i].property[2], &in[i].property[3]);
		scanf("%s", race);
		scanf("%s %s %s %s", priority[0], priority[1], priority[2], priority[3]);
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++)
				if(!strcmp(s[i], priority[j]))
					img[j] = i;
		qsort(in, n, sizeof(S), cmp);
		for(i = 0; i < n; i++)
			if(!strcmp(in[i].race, race))
				break;
		printf("Case #%d\n", ++tc);
		if(i == n){
			puts("Cards not found");
			continue;
		}
		for(; i < n; i++){
			if(!strcmp(in[i].race, race))
				printf("%s %d %d %d %d\n", in[i].race, in[i].property[0], in[i].property[1], in[i].property[2], in[i].property[3]);
			else
				break;
		}
	}
	return 0;
}