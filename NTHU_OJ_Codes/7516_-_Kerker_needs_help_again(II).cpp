#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
struct data{
    char name[100], ID[100];
}temp;
int main(){
    int n,i;
    char s[10000];
    while(scanf("%d", &n) > 0, n){
            queue<struct data> q1, q2, q3;
            for(i = 0; i < n; i++){
                scanf("%s%s", temp.ID, temp.name);
                int l = strlen(temp.ID);
                if(l <= 3)
                    q1.push(temp);
                else if(l <= 6)
                    q2.push(temp);
                else
                    q3.push(temp);
                gets(s);
            }
            puts("<326>");
            while(!q1.empty()){
                temp = q1.front();
                printf("%3s %s\n", temp.ID, temp.name);
                q1.pop();
            }
            puts("<328>");
            while(!q2.empty()){
                temp = q2.front();
                printf("%6s %s\n", temp.ID, temp.name);
                q2.pop();
            }
            puts("<mac>");
            while(!q3.empty()){
                temp = q3.front();
                printf("%9s %s\n", temp.ID, temp.name);
                q3.pop();
            }
            putchar(10);
    }
    return 0;
}
