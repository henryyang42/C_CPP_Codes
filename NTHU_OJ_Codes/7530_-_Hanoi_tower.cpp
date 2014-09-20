#include<stdio.h>
#include<stack>
#include<cmath>
using namespace std;
int ans[51];
bool issquare(int big, int small){
	int SQRT = sqrt(big + small);
	return SQRT*SQRT == big + small;
}
void makeans(){
	int i, j, k;
	for(k = 1; k < 51; k++){
		j = 1;
		stack<int> hanoi[51];
		while(1){
			for(i = 0; i < k; i++)
				if(hanoi[i].empty() || (!hanoi[i].empty() && issquare(j, hanoi[i].top()))){
					hanoi[i].push(j);
					break;
				}
			if(k <= i)
				break;
			j++;
		}
		ans[k] = j - 1;
	}
}
int main(){
	int n, t;
	makeans();
	while(scanf("%d", &t) > 0)while(t--){
		scanf("%d", &n);
		printf("%d\n", ans[n]);
	}
	return 0;
}
