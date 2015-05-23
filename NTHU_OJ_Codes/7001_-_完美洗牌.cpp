#include<stdio.h>
int card[52];
void print(int t){
	int i;
	printf("Case %d:", t);
	for(i = 0; i < 52; i++)
		if(i % 13 == 0)
			printf("\n%d", card[i]);
		else
			printf(" %d", card[i]);
	putchar(10);
}
void rearrange(int n){
	int i, j;
	int temp[52];
	for(i = 1; i <= 52; i++)
		card[i - 1] = i;
	for(i = 0; i < n; i++){
		for(j = 0; j < 52; j += 2)
			temp[j + 1] = card[j / 2], temp[j] = card[26 + j / 2];
		for(j = 0; j < 52; j++)
			card[j] = temp[j];
	}	
}
int main(){
	int i, n, t = 0, ct;
	while(scanf("%d", &ct) > 0)
		while(ct--)
			scanf("%d", &n), rearrange(n % 52), print(++t);
	return 0;
}
