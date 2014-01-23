#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;
int ct[1000010], isin[1010];
int main(){
	int i, n, j, testcase = 0;
	while(scanf("%d", &n) > 0, n){
		queue<int> t[1010]; 
		queue<int> bigqueue;
		int m, i, x;
		memset(ct, 0, sizeof(ct));
		memset(isin, 0, sizeof(isin));
		for(i = 1; i <= n; i++){
			scanf("%d", &m);
			while(m--)
				scanf("%d", &x), ct[x] = i;/*recode who belong to which team*/
		}
		printf("Scenario #%d\n", ++testcase);
		while(1){
			char s[10];
			scanf("%s", s);
			if(strcmp(s, "ENQUEUE") == 0){
				scanf("%d", &m);
				if(isin[ct[m]] == 0){
					isin[ct[m]] = 1;
					bigqueue.push(ct[m]);	
				}
				t[ct[m]].push(m);
			}
			else if(strcmp(s, "DEQUEUE") == 0){
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
			else if	(strcmp(s, "STOP") == 0){
				break;
			}
		}
		putchar(10);
	}
	return 0;
}
