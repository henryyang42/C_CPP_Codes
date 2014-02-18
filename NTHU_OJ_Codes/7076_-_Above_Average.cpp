#include<cstdio>

int main(){
	int n, t;
	double s[1001], tot, avg, above;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		above = tot = 0;
		for(int i = 0; i < n; i++)
			scanf("%lf", &s[i]), tot += s[i];
		avg = tot / n;
		for(int i = 0; i < n; i++)
			if(s[i] > avg)
				above++;
		printf("%.3lf%%\n", 100*above/n);
	}
	return 0;
}
