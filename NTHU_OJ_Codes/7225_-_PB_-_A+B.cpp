#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct data{
	int no;
	double cpu;
	char name[20];
}s[100001];
typedef struct data D;
int compare(const void *v , const void * o){
	D *p1 = (D*) v, *p2 = (D*) o;
	if(p1 -> cpu != p2 -> cpu)
		return (int)(10000.0*(p1 -> cpu) - 10000.0*(p2 -> cpu));
	else
		return p1 -> no - p2 -> no;
}
int main(){
	int a, i, j;
	double cpu;
	while(scanf("%d",&a)>0){
		for(i = 0; i < a; i++)
			scanf("%s %lf",s[i].name,&s[i].cpu), s[i].no = i,s[i].cpu -= fmod(s[i].cpu,0.001);
		qsort(s,a,sizeof(D),compare);
		for(i = 0; i < a; i++)
			printf("%d %s %.3lf\n",i + 1, s[i].name, s[i].cpu);
	}
    return 0;
}
