#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
struct data{
	int id, team;	
}ct[1000000];
int compare(const void *v, const void *o){
	return ((data*)v) -> id - ((data*)o) -> id;	
}
int whichteam(int m, int member){
	data temp; temp.id = m;
	data *ptr = (data*) bsearch(&temp, ct, member, sizeof(data), compare);
	return ptr -> team;
}
int isin[1010];
int main(){
	int i, n, j, testcase = 0, q, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &q);
		queue<int> t[1010]; 
		queue<int> bigqueue;
		int m, i, x, member = 0;
		memset(isin, 0, sizeof(isin));
		for(i = 1; i <= n; i++){
			scanf("%d", &m);
			while(m--)
				scanf("%d", &x), ct[member].id = x, ct[member++].team = i;/*recode who belong to which team*/
		}
		qsort(ct, member, sizeof(data), compare);
		if(testcase)
			putchar(10);
		printf("Case %d:\n", ++testcase);
		while(q--){
			char s[10];
			scanf("%s", s);
			if(strcmp(s, "PUSH") == 0){
				scanf("%d", &m);
				int team = whichteam(m, member);
				if(isin[team] == 0){
					isin[team] = 1;
					bigqueue.push(team);	
				}
				t[team].push(m);
			}
			else if(strcmp(s, "POP") == 0){
				if(t[bigqueue.front()].empty()){
					isin[bigqueue.front()] = 0;
					bigqueue.pop();
					printf("%d\n", t[bigqueue.front()].front());
					t[bigqueue.front()].pop();
				}
				else{
					printf("%d\n", t[bigqueue.front()].front());
					t[bigqueue.front()].pop();	
				}
			}
			else{
				break;
			}
		}
	}
	return 0;
}
