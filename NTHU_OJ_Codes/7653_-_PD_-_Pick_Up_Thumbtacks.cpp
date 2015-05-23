#include<cstdio>
#include<algorithm>
using namespace std;
struct Mine{
	int x, y, dis, id;
}mine[10000];
bool cmp(Mine a, Mine b){
	if(a.dis != b.dis)
		return a.dis < b.dis;
	return a.id < b.id;
}
int main(){
	int x, y, t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &x, &y, &n);
		for(int i = 0; i < n; i++){
			scanf("%d%d", &mine[i].x, &mine[i].y);
			mine[i].id = i+1;
			mine[i].dis = (mine[i].x-x)*(mine[i].x-x)+(mine[i].y-y)*(mine[i].y-y);
		}
		sort(mine, mine+n, cmp);
		for(int i = 0; i < n; i++)
			printf("#%d: %d %d\n", mine[i].id, mine[i].x, mine[i].y);
		if(t)
			putchar(10);
	}
	return 0;
}

