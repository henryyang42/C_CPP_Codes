#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct data{
	int l;
	char *ptr;
}D;
D s[2000000];
int a, tot;char temp[2000000];
void check(int ii, int jj){
	strcpy(temp, s[ii].ptr);
	strcpy(temp + s[ii].l, s[jj].ptr);
	int l = s[ii].l + s[jj].l, i, j;
	temp[l] = 0;
	for(i = 0, j = l - 1; i < j; i++, j--)
		if(temp[i] != temp[j])
			return;
	tot++;	
}
int main(){
	int  l, i, j;
	while(scanf("%d", &a) > 0){
		for(i = 0; i < a; i++){
			scanf("%d", &l);
			s[i].ptr = (char*)malloc(l + 1);
			scanf("%s", s[i].ptr);
			s[i].l = l;
		}
		tot = 0;
		for(i = 0; i < a; i++)
			for(j = 0; j < a; j++)
				check(i, j);
		printf("%d\n", tot);
	}
    return 0;
}
