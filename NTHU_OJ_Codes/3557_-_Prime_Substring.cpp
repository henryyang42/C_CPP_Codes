#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[1000], prime[100001] = {1, 1};
int to_int(int i, int j){
	int x = 0;
	for(; i <= j; i++)
		x = x*10 + s[i] - '0';
	if(!prime[x])
		return x;
	return 0;
}
int main(){
	for(int i = 2; i < 100000; i++)
		if(prime[i] == 0)
			for(int j = i * 2; j < 100000; j += i)
				prime[j] = 1;
	while(scanf("%s", s) > 0){
		if(strlen(s) == 1 && s[0] == '0')
			break;
		int Max = 0;
		for(int i = 0; i < strlen(s); i++)
			for(int j = i; j < i + 5 && j < strlen(s); j++)
				Max = max(Max, to_int(i, j));
		printf("%d\n", Max);
	}
	return 0;
}
