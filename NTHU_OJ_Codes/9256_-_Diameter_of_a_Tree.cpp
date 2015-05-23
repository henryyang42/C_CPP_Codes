#include<stdio.h>
#include<queue>
#include<list>
#include<string.h>
using namespace std;
list<int> l[200001];
char isvisit[200001];
struct state{
	int to, len;
};
int dis;
int bfs(int last){
	memset(isvisit, 0, sizeof(isvisit));
	queue<state> q;
	state s, la;
	s.to = last;
	s.len = 0;
	q.push(s);
	while(!q.empty()){
	la = q.front();
	isvisit[la.to] = 1;
	q.pop();
	for(list<int>::iterator it = l[la.to].begin(); it != l[la.to].end(); it++)
		if(!isvisit[*it]){
			state temp;
			temp.to = *it;
			dis = temp.len = la.len + 1;
			q.push(temp);
		}
	}
	last = la.to;
	return last;	
}
int n;
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b, last;
		scanf("%d", &n);
		for(int i = 0; i < n - 1; i++)
			scanf("%d%d", &a, &b), l[a].push_front(b), l[b].push_front(a);
		bfs(bfs(1));
		printf("%d\n", dis);
		for(int i = 0; i < 200001; i++)
			l[i].clear();
	}
	return 0;
}
