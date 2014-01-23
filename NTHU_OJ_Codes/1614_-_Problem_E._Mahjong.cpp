#include <stdio.h>
#include <string.h>
int ct, ans[10];
void Chow(int card[10], int start){
	for(int i = start; i <= 7; i++)
		while(card[i] && card[i + 1] && card[i + 2])
			card[i]--, card[i + 1]--, card[i + 2]--;
}
void Pong(int card[10], int start){
	for(int i = start; i <= 9; i++)
		if(card[i] >= 3)
			card[i] -= 3;
}
void Pair(int card[10], int start){
	for(int i = start; i <= 9; i++)
		if(card[i] >= 2){
			card[i] -= 2;
			break;
		}
}
int remain(int card[10]){
	int tot = 0;
	for(int i = 1; i <= 9; i++)
		tot += card[i];
	return tot;
}
void calc(int card[10]){
	char visit[10] = {0};
	for(int t = 1; t <= 9; t++)
		if(card[t] < 4)
			for(int pa = 1; pa <= 9 && !visit[t]; pa++)
				for(int pong = 1; pong <= 9 && !visit[t]; pong++)
					for(int chow = 1; chow <= 7 && !visit[t]; chow++){
						int test[10];
						memcpy(test, card, sizeof(test));
						test[t]++;
						Chow(test, chow);
						Pong(test, pong);
						Pair(test, pa);
						if(remain(test) == 0){
							ans[ct++] = t;
							visit[t] = 1;
							break;
						}
						////////////////////
						memcpy(test, card, sizeof(test));
						test[t]++;
						Pong(test, pong);
						Chow(test, chow);
						Pair(test, pa);
						if(remain(test) == 0){
							ans[ct++] = t;
							visit[t] = 1;
							break;
						}
						////////////////////
						memcpy(test, card, sizeof(test));
						test[t]++;
						Pair(test, pa);
						Pong(test, pong);
						Chow(test, chow);
						if(remain(test) == 0){
							ans[ct++] = t;
							visit[t] = 1;
							break;
						}
						////////////////////
						memcpy(test, card, sizeof(test));
						test[t]++;
						Pair(test, pa);
						Chow(test, chow);
						Pong(test, pong);
						if(remain(test) == 0){
							ans[ct++] = t;
							visit[t] = 1;
							break;
						}
						////////////////////
						memcpy(test, card, sizeof(test));
						test[t]++;
						Chow(test, chow);
						Pair(test, pa);
						Pong(test, pong);
						if(remain(test) == 0){
							ans[ct++] = t;
							visit[t] = 1;
							break;
						}
						////////////////////
						memcpy(test, card, sizeof(test));
						test[t]++;
						Pong(test, pong);
						Pair(test, pa);
						Chow(test, chow);
						if(remain(test) == 0){
							ans[ct++] = t;
							visit[t] = 1;
							break;
						}
					}
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int x, card[10] = {0};
		for(int i = 0; i < 13; i++)
			scanf("%d", &x), card[x]++;
		ct = 0;
		calc(card);
		if(ct)
			for(int i = 0; i < ct; i++){
				if(i)
					putchar(32);
				printf("%d", ans[i]);
			}
		else
			putchar('0');
		putchar(10);
	}
    return 0;
}
