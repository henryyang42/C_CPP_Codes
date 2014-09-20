#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
char s[1001][1001];

int main(){
	int n, ct = 0;
	scanf("%d", &n);
	while(n--){
			if(ct++) putchar(10);
		memset(s, 0, sizeof(s));
		int D, P, a, b;
		scanf("%d%d", &P, &D);
		for(int i = 0; i < D; i++)
			scanf("%d%d", &a, &b), s[a][b] = 1, s[b][a] = 1;
		char isvisit[1001] = {0};
		int ans[1001] = {0};
		queue<int> num, ct;
		num.push(0), ct.push(0);
		while(!num.empty()){
			int NUM = num.front();
			isvisit[NUM] = 1;
			num.pop();
			int CT = ct.front();
			if(!ans[NUM])
				ans[NUM] = ct.front();
			ct.pop();
			for(int j = 0; j < P; j++)
				if(s[NUM][j] && !isvisit[j])
					num.push(j), ct.push(CT + 1), isvisit[j] = 1;
		}
		for(int i = 1; i < P; i++) printf("%d\n", ans[i]);
	}
	return 0;
}
