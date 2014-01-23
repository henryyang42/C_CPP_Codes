#include<stdio.h>
int top[30001], down[30001], Fdown[30001], Ftop[30001], ct[30001];
int find_down(int x){
	return x == Fdown[x] ? x : (Fdown[x] = find_down(Fdown[x]));
}
int find_top(int x){
	return x == Ftop[x] ? x : (Ftop[x] = find_top(Ftop[x]));
}
int main(){
	int t;
	while(scanf("%d", &t) > 0){
		int i, x, y;
		char op[10];
		for(i = 0; i < 30001; i++)
			top[i] = down[i] = Fdown[i] = Ftop[i] = i, ct[i] = 0;
		while(t--){
			scanf("%s", op);
			if(op[0] == 'M'){
				scanf("%d%d", &x, &y);
				int ftop = find_top(y), fdown = find_down(x);
				if(find_top(x) != ftop){
					down[fdown] = ftop;
					top[ftop] = fdown;
					Fdown[fdown] = ftop;
					Ftop[ftop] = fdown;
				}
			}
			else{
				scanf("%d", &x);
				printf("%d\n", ct[x]);
			}
		}
	}
	return 0;
}
