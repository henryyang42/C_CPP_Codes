#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
int s[100001];
int main(){
	int n;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while(scanf("%d", &n) > 0){
		for(int i = 0; i < n; i++){
			scanf("%d", &s[i]);
		}
		sort(s, s+n);
		int Min = 1e9;
		for(int i = n-1; i >= 0; i--){
			int x = s[i] / 2 + s[i] % 2;
			int *ptr = lower_bound(s, s+i, x);
			Min = min(Min, n-1-i+(int)(ptr-s));
			//printf("lower bound of %d is at %d (%d)\n",x,  (int)(ptr -s), *ptr);
		}
		/*for(int i = 0; i < n; i++){
			int x = s[i] * 2;
			int *ptr = lower_bound(s+i, s+n-1, x);
			if(*ptr == x){
				while(ptr < s+n-1 && *ptr == x)
					ptr++;
				if(*ptr > x)
					ptr--;
			}
			else if(*ptr > x && ptr > s)
				ptr--;
			Min = min(Min, i+(int)(s+n-1-ptr));
			//printf("lower bound of %d is at %d (%d), Min = %d\n",x,  (int)(ptr -s), *ptr, Min);

		}*/
		printf("%d\n", Min);
	}
	return 0;
}

