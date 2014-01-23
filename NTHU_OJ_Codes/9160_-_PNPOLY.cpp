#include<stdio.h>
struct point{
	long long x, y;
}p[100001], tt;
int n;
int in(){
	int i, j, c = 0;
	for(i = 0, j = n - 1; i < n; j = i++){
		//if((p[i].x - p[j].x) * (p[i].y - tt.y) != (p[i].y - p[j].y) * (p[i].x - tt.x) && ((p[i].y > tt.y && tt.y > p[j].y)||(p[j].y > tt.y && tt.y > p[i].y)) && (p[j].x > tt.x||p[i].x > tt.x))
			//printf("i = %d, j = %d\n", i, j),
		if( ((p[i].y>tt.y) != (p[j].y>tt.y)) &&
	 		((p[j].y-p[i].y) > 0 && (tt.x * (p[j].y-p[i].y) < (p[j].x-p[i].x) * (tt.y-p[i].y) + p[i].x *   (p[j].y-p[i].y))
				|| (p[j].y-p[i].y) < 0 && (tt.x * (p[j].y-p[i].y)  > (p[j].x-p[i].x) * (tt.y-p[i].y) + p[i].x *  (p[j].y-p[i].y))
				))
			 c++;
		if((p[i].x - p[j].x) * (p[i].y - tt.y) == (p[i].y - p[j].y) * (p[i].x - tt.x))
			return 0;
	}
	//printf("c = %d\n", c);
	return c;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int i, j, q;
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%lld%lld", &p[i].x, &p[i].y);
		scanf("%d", &q);
		while(q--){
			scanf("%lld%lld", &tt.x, &tt.y);
			if(in() % 2)
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}
