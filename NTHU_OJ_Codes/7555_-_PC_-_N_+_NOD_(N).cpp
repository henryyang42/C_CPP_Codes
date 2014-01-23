#include<stdio.h>
#include<math.h>
int ct[2000001] = {0}, prime[1000001], p = 0, anss[1000001];
char s[1000001] = {0};
int main(){
	for(int i = 2; i < 1000000; i++)
		if(!s[i]){
			prime[p++] = i;
			for(int j = 2 * i; j < 1000000; j+= i)
				s[j] = 1;
		}
		anss[1] = 1, anss[2] = 2;
	for(int i = 3; i < 64728; i++){
		int temp = anss[i - 1], sqrt_temp = (int)sqrt(anss[i-1]), ans = 1;
		for(int j = 0; j < p && prime[j] <= sqrt_temp; j++){
			int ctt = 1;
			while(temp % prime[j] == 0)
				ctt++, temp /= prime[j];
			ans *= ctt;
		}
		anss[i] = anss[i - 1] + ans * (temp > 1 ? 2 : 1);
	}
	for(int i = 0; i < 64728; i++)ct[anss[i]] = i + 1;
	for(int i = 1; i < 1000001; i++)
		if(!ct[i])
			ct[i] = ct[i - 1];
	int n, ca = 0;
	scanf("%d", &n);
	while(n--){
		int A, B;
		scanf("%d%d", &A, &B);
		printf("Case %d: %d\n", ++ca, ct[B] - ct[A - 1]);
	}
	return 0;
}
