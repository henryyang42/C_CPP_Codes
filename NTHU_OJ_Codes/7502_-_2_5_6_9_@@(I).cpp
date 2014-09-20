#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<queue>
using namespace std;
char s[100], ans[100], m[100][100][100] = {0};
int main(){
    strcpy(m[2][0], "22222");
    strcpy(m[2][1], "    2");
    strcpy(m[2][2], "22222");
    strcpy(m[2][3], "2    ");
    strcpy(m[2][4], "22222");

    strcpy(m[5][0], "55555");
    strcpy(m[5][1], "5    ");
    strcpy(m[5][2], "55555");
    strcpy(m[5][3], "    5");
    strcpy(m[5][4], "55555");

    strcpy(m[6][0], "66666");
    strcpy(m[6][1], "6    ");
    strcpy(m[6][2], "66666");
    strcpy(m[6][3], "6   6");
    strcpy(m[6][4], "66666");

    strcpy(m[9][0], "99999");
    strcpy(m[9][1], "9   9");
    strcpy(m[9][2], "99999");
    strcpy(m[9][3], "    9");
    strcpy(m[9][4], "99999");




    int t;
    queue<int> q;
    int i, j, l, k;
   scanf("%d", &t);
   getchar();
   while(t--){
        while(gets(s) > 0){
            if(strlen(s) == 0)
                break;
            for(i = 0; i < strlen(s); i++)
                if(isdigit(s[i]))
                    q.push(s[i] - '0');
            l = 0;
            while(!q.empty())
               ans[l++] =  q.front(), q.pop();
            for(i = 0;i < 5; i++, putchar(10))
                for(j = 0; j < l; j++)
                if(j == l - 1)
                    printf("%s", m[ans[j]][i]);
                    else
                    printf("%s ", m[ans[j]][i]);
            puts("");
        }
   }
    return 0;
}
