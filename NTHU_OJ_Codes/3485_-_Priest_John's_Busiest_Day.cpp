#include<stdio.h>
#include<queue>
using namespace std;
struct line{
	long long f, r, mid;
	bool operator < (const line &L) const{
		return mid > L.mid;
	}
}L;
int main(){
	int n;
	while(scanf("%d", &n), n){
		priority_queue<line> q;
		for(int i = 0; i < n; i++){
			scanf("%lld%lld", &L.f, &L.r);
			L.f *= 2, L.r *= 2;
			L.mid = (L.f + L.r) / 2;
			q.push(L);
		}
		int fg = 1;
		long long Max = 0;
		while(!q.empty() && fg){
			L = q.top(), q.pop();
			if(Max <= L.f)
				Max = L.mid + 1;
			else if(Max + (L.mid - L.f + 1) <= L.r)
				Max = Max + (L.mid - L.f + 1);
			else
				fg = 0;
		}
		if(fg)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
