#include<stdio.h>
#include<map>

using namespace std;
struct gift{
	int time, L;
	bool operator < (const gift G) const{
		return L == G.L ? (time < G.time) : (L > G.L);
	}
}G;
int main(){
	int ans, vol, n, x, ct = 0, v;
	while(scanf("%d%d", &vol, &n), n + vol){
		ans = v = 0;
		map<int, gift> m;
		map<gift, int> checkup;
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			if(m.find(x) != m.end()){
				checkup.erase(m[x]);
				m[x].L++;
				checkup[m[x]] = x;
			}
			else{
				if(v < vol){
					v++;
				}
				else{
					ans++;
					m.erase(checkup.begin() -> second);
					checkup.erase(checkup.begin() -> first);
				}
				G.time = i;
				G.L = 1;
				m[x] = G;
				checkup[G] = x;
			}
		}
		printf("Case %d: %d\n", ++ct, ans);
	}
	return 0;
}
