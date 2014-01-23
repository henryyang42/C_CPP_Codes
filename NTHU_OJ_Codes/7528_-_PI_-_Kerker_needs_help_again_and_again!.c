#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    char name[100];
    char id[100];
    int tag;
}s326[200], s328[200], smac[200];
typedef struct student S;
int compare(const void *v, const void *o){
    S *p1 = (S*)v, *p2 = (S*)o;
    if(strcmp(p1 -> name, p2 -> name) != 0)
        return strcmp(p1 -> name, p2 -> name);
    else
        return p1 -> tag - p2 -> tag;
}
int main(){
    int n;
    char s[1000];
    while(scanf("%d", &n) > 0){
        int i, ct326 = 0, ct328 = 0, ctmac = 0;
        int flag1 = 1, flag2 = 1, flag3 = 1;
        for(i = 0; i < n; i++){
            scanf("%s",s);
            if(strcmp(s, "326") == 0){
                s326[ct326].tag = i;
                scanf(" %s%s", s326[ct326].id, s326[ct326].name);ct326++;
          gets(s);flag1 = 0; }
            else if(strcmp(s, "328") == 0){
               s328[ct328].tag = i;
                scanf(" %s%s", s328[ct328].id, s328[ct328].name);ct328++;
           gets(s); flag2 = 0;/*s328[ct328--].id);*/ }
           else  if(strcmp(s, "mac") == 0){
               smac[ctmac].tag = i;
                scanf(" %s%s", smac[ctmac].id, smac[ctmac].name);ctmac++;
            gets(s);flag3 = 0;}

        }
        qsort(s326, ct326, sizeof(S), compare);
             qsort(s328, ct328, sizeof(S), compare);
              qsort(smac, ctmac, sizeof(S), compare);
        puts("<326>");
        for(i = 0; i < ct326; i++)
            printf("%s %s\n", s326[i].id, s326[i].name);
        puts("<328>");
        for(i = 0; i < ct328; i++)
            printf("%s %s\n", s328[i].id, s328[i].name);
        puts("<mac>");
        for(i = 0; i < ctmac; i++)
            printf("%s %s\n", smac[i].id, smac[i].name);
        putchar(10);
    }
	return 0;
}
