#include<stdio.h>
#include<string.h>
char s[10001], t[33][33], visit[33][33];
int main(){
    char di[] = {1, 0, -1, 0};
    char dj[] = {0, 1, 0, -1};
    while(gets(s) > 0){
        int l = strlen(s), sz, i, j, x, nexti, nextj, vec;
        memset(visit, 1, sizeof(visit));
        for(sz = 0; sz*sz < l; sz++);
        for(i = 0; i < sz; i++)
            for(j = 0; j < sz; j++)
                visit[i][j] = 0;
        for(i = l; i < sz*sz; i++)
            s[i] = 32;
        x = sz*sz;
        vec = i = j = 0;
        while(x){
            t[i][j] = s[sz*sz - x--];
            visit[i][j] = 1;
            nexti = i + di[vec];
            nextj = j + dj[vec];
            if(visit[nexti][nextj] || nexti < 0 || nextj < 0)
                vec = (vec+1) % 4;
            i = i + di[vec];
            j = j + dj[vec];
        }
        for(i = 0; i < sz; i++)
            for(j = 0; j < sz; j++)
                s[i*sz+j] = t[i][j];
        l = sz*sz-1;
        while(s[l] == 32)
            l--;
        s[l+1] = 0;
        puts(s);
    }
	return 0;
}
