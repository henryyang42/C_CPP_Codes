#include<stdio.h>
#include<math.h>
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		double p, r;
		int k, n;
		scanf("%d%lf%d", &n, &p, &k);
		r = pow(1 - p, n);
		if(p == 0)
			puts("0.0000");
		else
			printf("%.4lf\n", pow(1 - p, k - 1) * p / (1 - r)+ 1e-7);
	}
	return 0;
}
