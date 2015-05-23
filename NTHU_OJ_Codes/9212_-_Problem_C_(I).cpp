#include<stdio.h>
struct rect{
	int x1, y1, x2, y2;
}r[1001];
int leader[1001], ct[1001];
int find(int x){
	return x == leader[x] ? x : (leader[x] = find(leader[x]));
}
int ifunion(rect r1, rect r2){
	if((!(r1.x1 > r2.x1 || r1.x2 < r2.x1) || !(r1.x1 > r2.x2 || r1.x2 < r2.x2))
		&& (!(r1.y1 > r2.y1 || r1.y2 < r2.y1) || !(r1.y1 > r2.y2 || r1.y2 < r2.y2)))
		return 1;
	if(r1.y2 > r2.y1 && r1.y2 > r2.y2 && r2.x2 > r1.x1 && r2.x2  > r1.x2
	&& r1.x2 > r2.x1 && r1.x1 > r2.x1 && r2.y2 > r1.y1 && r2.y1  > r1.y1)
		return 1;
	rect temp = r1;
	r1 = r2, r2 = temp;
	if((!(r1.x1 > r2.x1 || r1.x2 < r2.x1) || !(r1.x1 > r2.x2 || r1.x2 < r2.x2))
		&& (!(r1.y1 > r2.y1 || r1.y2 < r2.y1) || !(r1.y1 > r2.y2 || r1.y2 < r2.y2)))
		return 1;
	if(r1.y2 > r2.y1 && r1.y2 > r2.y2 && r2.x2 > r1.x1 && r2.x2  > r1.x2
	&& r1.x2 > r2.x1 && r1.x1 > r2.x1 && r2.y2 > r1.y1 && r2.y1  > r1.y1)
		return 1;
	return 0;
}
/*int ifunion(rect r1, rect r2){
	if(r1.x2 >= r2.x1 && r1.y2 >= r2.y1)
		return 1;
	if(r2.x2 >= r1.x1 && r2.y2 >= r1.y1)
		return 1;
	if(r1.x2 >= r2.x1 && r1.y1 <= r2.y2)
		return 1;
	if(r2.x2 >= r1.x1 && r2.y1 <= r1.y2)
		return 1;
	return 0;
}*/
int main(){
	int n, i, j, max;
	while(scanf("%d", &n) > 0, n){
		for(i = 0; i < n; i++)
			scanf("%d%d%d%d", &r[i].x1, &r[i].y1, &r[i].x2, &r[i].y2), leader[i] = i, ct[i] = 0;
		for(i = 0; i < n - 1; i++)
			for(j = i + 1; j < n; j++)
				if(ifunion(r[i], r[j])){
					int fa = find(i), fb = find(j);
					leader[fa] = fb;
				}
		for(i = 0; i < n; i++)
			ct[find(i)]++;
		for(i = max = 0; i < n; i++)
			if(max < ct[i])
				max = ct[i];
		printf("%d\n", max);
	}
	return 0;
}
