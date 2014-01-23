#include<stdio.h>
#include<map>
using namespace std;
int s[4][10000];
int main(){
	int t, n, fg = 0;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < 4; j++)
				scanf("%d", &s[j][i]);
		map<int, int> m[2];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				m[0][s[0][i] + s[1][j]]++, m[1][s[2][i] + s[3][j]]++;
		map<int, int>::iterator it = m[0].begin();
		long long int ans = 0;
		while(it != m[0].end())
			ans += (it -> second) * m[1][-(it -> first)], it++;
		if(fg++)
			putchar(10);
		printf("%lld\n", ans);

	}
	return 0;
}
