#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct d{
	char name[21], cpu[10];
	int id;
}s[100001];
int compare(const void *v, const void *o){
	struct d *p1 = (struct d*)v, *p2 = (struct d*) o;
	if(strcmp(p1 -> cpu, p2 -> cpu) != 0)
		return strcmp(p1 -> cpu, p2 -> cpu);
	return p1 -> id - p2 -> id;
}
int main(){
	int t;
	while(scanf("%d", &t) > 0){
		int i;
		for(i = 0; i < t; i++)
			scanf("%s%s", s[i].name, s[i].cpu), s[i].id = i;
		qsort(s, t, sizeof(struct d), compare);
		for(i = 0; i < t; i++)
			printf("%d %s %s\n",i + 1, s[i].name, s[i].cpu);
	}
	return 0;
}
