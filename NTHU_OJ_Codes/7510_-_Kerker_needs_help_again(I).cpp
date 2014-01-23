#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
struct data{
    char name[100], ID[100];
	int l;
}temp;
int main(){
    int n,i;
    char s[10000],  room[10];
    while(scanf("%d", &n) > 0, n){
            queue<struct data> q1, q2, q3;
            int l1 = 0, l2 = 0, l3 = 0;
            for(i = 0; i < n; i++){
                scanf("%s%s%s", room, temp.ID, temp.name);
                temp.l = strlen(temp.ID);
                if(strcmp(room, "326") == 0){
                    q1.push(temp);
                    if(temp.l > l1)
                    	l1 = temp.l;
				}
                else if(strcmp(room, "328") == 0){
                    q2.push(temp);
                    if(temp.l > l2)
                    	l2 = temp.l;
				}
                else if(strcmp(room, "mac") == 0){
                    q3.push(temp);
                    if(temp.l > l3)
                    	l3 = temp.l;
				}
                gets(s);
            }
            puts("<326>");
            while(!q1.empty()){
                temp = q1.front();
                for(i = 0; i < l1 - temp.l; i++)
                	putchar(32);
                printf("%s %s\n", temp.ID, temp.name);
                q1.pop();
            }
            puts("<328>");
            while(!q2.empty()){
                temp = q2.front();
                for(i = 0; i < l2 - temp.l; i++)
                	putchar(32);
                printf("%s %s\n", temp.ID, temp.name);
                q2.pop();
            }
            puts("<mac>");
            while(!q3.empty()){
                temp = q3.front();
                for(i = 0; i < l3 - temp.l; i++)
                	putchar(32);
                printf("%s %s\n", temp.ID, temp.name);
                q3.pop();
            }
            putchar(10);
    }
    return 0;
}
