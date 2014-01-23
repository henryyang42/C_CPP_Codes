#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct data{
	int no;
	int grade;
	char name[11];
}s[100001];
typedef struct data D;
int compare(const void *v , const void * o){
	D *p1 = (D*) v, *p2 = (D*) o;
	if(p1 -> grade != p2 -> grade)
		return p1 -> grade - p2 -> grade;
	else
		return p1 -> no - p2 -> no;
}
int main(){
	int a, i, j, t;
	while(scanf("%d", &t) > 0)while(t--){
		scanf("%d", &a);
		for(i = 0; i < a; i++)
			scanf("%s %d", s[i].name, &s[i].grade), s[i].no = i;
		qsort(s,a,sizeof(D),compare);
		for(i = 0; i < a; i++)
			printf("%s %d\n",s[i].name, s[i].grade);
	}
    return 0;
}
