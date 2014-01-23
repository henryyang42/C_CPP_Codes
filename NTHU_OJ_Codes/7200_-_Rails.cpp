#include<stdio.h>
#include<stack>
using namespace std;
int main(){
	int n;
	while(scanf("%d", &n) > 0, n){
		while(1){
			stack<int> s;
			int i, m[1001], now = 1;
			scanf("%d", &m[0]);
			if(m[0] == 0)
				break;
			for(i = 1; i < n; i++)
				scanf("%d", &m[i]);
			for(i = 0; i < n; i++){
				while(now != m[i] && now <= m[i])
					s.push(now++);
				if(now == m[i])
					now++;
				if(!s.empty() && m[i] == s.top())
					s.pop();
			}
			if(s.empty())
				puts("Yes");
			else
				puts("No");
		}
		putchar(10);	
	}
	return 0;
}
