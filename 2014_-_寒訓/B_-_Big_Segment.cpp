#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
int s[100001][2];
int main(){
	int n;
	while(scanf("%d", &n) > 0){
		int ans = -1, Max = -1, Min = 1e9;
		for(int i = 0; i < n; i++){
			scanf("%d%d", &s[i][0], &s[i][1]);
			Max = max(Max, s[i][1]);
			Min = min(Min, s[i][0]);
		}
		for(int i = 0; i < n; i++)
			if(s[i][0] <= Min && s[i][1] >= Max)
				ans = i+1;
		printf("%d\n", ans);
	}
	return 0;
}
