#include<stdio.h>
#include<algorithm>
#include<string.h>
int s[1000000];
int inds[50002];
int indb[50002];
int main(){
	int n;
	while(scanf("%d", &n) > 0){
		memset(inds, 0, sizeof(inds));
		memset(indb, 0, sizeof(indb));
		for(int i = 0; i < n; i++)
			scanf("%d", s + i);
		std::sort(s, s + n);
		for(int i = 0; i < n; i++){
			inds[s[i]] = i + 1;
			while(i < n && s[i] == s[i + 1])
				i++;
		}
		for(int i = n - 1; i >= 0; i--){
			indb[s[i]] = i + 1;
			while(i > 0 && s[i] == s[i - 1])
				i--;
		}
		for(int i = 50000; i > 0; i--)
			if(inds[i] == 0)
				inds[i] = inds[i + 1];
		for(int i = 1; i <= 50000; i++)
			if(indb[i] == 0)
				indb[i] = indb[i - 1];
		int ans = 10000000;
		for(int i = 1; i <= 25000; i++)
			if(inds[i] && indb[i * 2]){
				int small = inds[i], big = indb[2 * i], temp;
				temp = n - (big - small + 1);
				if(ans > temp)
					ans = temp;
			}
		printf("%d\n", ans);
	}
	return 0;
}
