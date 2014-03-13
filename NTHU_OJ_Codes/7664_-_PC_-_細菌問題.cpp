#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define MOD 1000000007
using namespace std;
long long ori[2][2] = {{2, 1}, {1, 3}};
void mul(long long a[2][2], long long b[2][2]){
	long long temp[2][2] = {};
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			for(int k = 0; k < 2; k++)
				temp[i][j] += (a[i][k] * b[k][j]) % MOD;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			a[i][j] = temp[i][j];
}
void get(long long a[2][2], long long n){
	long long temp[2][2];
	memcpy(temp, ori, sizeof(ori));
	for(int i = 0; i < 64; i++){
		if(1&(n >> i))
			mul(a, temp);
		mul(temp, temp);
	}
}
int main(){
	//freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	long long a, b, n;
	while(scanf("%lld%lld%lld", &a, &b, &n) > 0){
		long long ans[2][2] = {{1, 0}, {0, 1}};
		get(ans, n);
		printf("%lld %lld\n", (ans[0][0]*a+ans[0][1]*b) % MOD, (ans[1][0]*a+ans[1][1]*b) % MOD);
	}
	return 0;
}