#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<list>
using namespace std;
list<int> l[100010];
int ans[100010], stack[100011], sz;
char s[100011];
int n, seq, space;
void dfs(int x){
	s[x] = 1;
	list<int>::iterator it = l[x].begin();
	while(it != l[x].end()){
		if(!s[*it])
			dfs(*it);
		it++;
	}
	stack[sz++] = x;
}
int main(){
    int t;
    while(scanf("%d%s", &n, s) > 0){
    	for(int i = 0; i <= n + 1; i++)
    		l[i].clear();
        for(int i = 0; s[i]; i++){
        	if(s[i] == '<')
        		l[i + 1].push_back(i + 2);
        	else
        		l[i + 2].push_back(i + 1);
        }
        memset(s, 0, sizeof(s));
        sz = 0;
        for(int i = n; i >= 1; i--)
        	if(!s[i])
        		dfs(i);
		while(--sz >= 0)
			printf("%d%s", stack[sz], sz ? " " : "");
        putchar(10);
    }
    return 0;
}

