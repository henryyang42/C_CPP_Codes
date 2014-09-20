#include<stdio.h>
#include<string.h>
int ct = 0, target;
char name[301][100], parent[301], child[301];
char adj[301][301] = {0};
char isvisit[301], relation[1000], ans[1000];
int getid(char s[]){
	int i;
	for(i = 0; i < ct; i++)
		if(strcmp(s, name[i]) == 0)
			return i;
	return -1;
}
void dfs(int now, int dep){
	isvisit[now] = 1;
	if(now == target){
			relation[dep] = 0;
		strcpy(ans, relation);
		return;
	}
	int j;
	for(j = 0; j < ct; j++)
		if(adj[now][j] && !isvisit[j])
			relation[dep] = adj[now][j] == 1 ? 'D' : 'U', dfs(j, dep + 1);
}
void find_relation(int a, int b){
	target = b;
	memset(ans, 0, sizeof(ans));
	dfs(a, 0);
	int l = strlen(ans), U = 0, D = 0, i;
	if(l == 0)
		puts("no relation");
	else{
		for(i = 0; i < l; i++)
			if(ans[i] == 'D') D++;
			else if(ans[i] == 'U') U++;
		if(U == 0){
			for(i = 0; i < D - 2; i++)
				printf("great ");
			if(D >= 2)
				printf("grand ");
			puts("child");
			return;
		}
		if(D == 0){
			for(i = 0; i < U - 2; i++)
				printf("great ");
			if(U >= 2)
				printf("grand ");
			puts("parent");
			return;
		}
		if(D == 1 && U == 1 && ans[0] == 'D'){
			puts("sibling");
			return;
		}
		else{
			printf("%d cousin", D - 1 > U - 1 ? U - 1 : D - 1);
			if(D - U)
				printf(" removed %d", D - U > 0 ? D - U : U - D);
			putchar(10);
		}
	}
}
int main(){
	while(scanf("%s%s", child, parent) > 0){
		if(strcmp(child, "no.child") == 0) break;
		if(getid(child) == -1)
			strcpy(name[ct++], child);
		if(getid(parent) == -1)
			strcpy(name[ct++], parent);
		int id_child = getid(child), id_parent = getid(parent);
		adj[id_child][id_parent] = 1;
		adj[id_parent][id_child] = -1;
	}
	while(scanf("%s%s", child, parent) > 0){
		memset(isvisit, 0, sizeof(isvisit));
		memset(relation, 0, sizeof(relation));
		find_relation(getid(child), getid(parent));
	}
	return 0;
}
