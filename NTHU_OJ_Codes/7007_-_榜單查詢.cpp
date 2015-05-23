#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<list>
using namespace std;
list<char*> grade[1001];
list<char*>::iterator it;
int rank[200001], ct = 1, sz[1001];
int main(){
	int n, q, g, r;
	char s[100], *ptr;
	scanf("%d%d", &n, &q);
	for(int i = 0; i <= 200000; i++)
		rank[i] = -1;
	for(int i = 0; i < n; i++){
		scanf("%s%d", s, &g);
		ptr = (char*)malloc(sizeof(char) * strlen(s) + 1);
		strcpy(ptr, s);
		grade[g].push_back(ptr);
		sz[g]++;
	}
	for(int i = 1000; i >= 0; i--){
		if(sz[i])
			rank[ct] = i, ct += sz[i];
	}
	for(int i = 1; i <= q; i++){
		printf("Query %d: ", i);
		scanf("%d", &r);
		if(r < 0 || r > n || rank[r] == -1)
			puts("null");
		else{
			printf("%d\n", rank[r]);
			it = grade[rank[r]].begin();
			while(it != grade[rank[r]].end())
				puts(*it), it++;
		}

	}
	return 0;
}
