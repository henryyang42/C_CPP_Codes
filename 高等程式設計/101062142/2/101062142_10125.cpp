#include<map>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int overlap(int a, int b, int c, int d){
	return a == c || a == d || b == c || b == d;
}
int main(){
	int n, s[1001];
	while(scanf("%d", &n), n){
		int d, fg = 0;
		map<int, vector<pair<int, int> > > m;
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		sort(s, s+n);
		reverse(s, s+n);
		for(int i = 0; i < n; i++)
			for(int j = i+1; j < n; j++)
				m[s[i]+s[j]].push_back(make_pair(s[i], s[j]));
		for(int i = 0; i < n; i++)
			for(int j = i+1; !fg && j < n; j++)
				if(i != j){
					vector<pair<int, int> > *v = & m[s[i]-s[j]];
					vector<pair<int, int> >::iterator it;
					if(v -> size()){
						it = v -> begin();
						while(it != v -> end()){
							if(!overlap(s[i], s[j], it-> first, it-> second)){
								fg = 1;
								d = s[i];
								break;
							}
							it++;
						}
					}
				}
		if(fg)
			printf("%d\n", d);
		else
			puts("no solution");
	}
	return 0;
}
