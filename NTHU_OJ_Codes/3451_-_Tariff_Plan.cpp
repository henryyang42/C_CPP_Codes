#include<math.h>
#include<stdio.h>

int main(){
	int t, n, ct = 0;
	double x, M_ans, J_ans;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		M_ans = J_ans = 0;
		while(n--){
			scanf("%lf", &x);
			x++;
			J_ans += ceil(x / 60) * 15;
			M_ans += ceil(x / 30) * 10;
		}
		printf("Case %d: ", ++ct);
		if(M_ans > J_ans)
			printf("Juice %.0lf\n", J_ans);
		else if( J_ans > M_ans)
			printf("Mile %.0lf\n", M_ans);
		else
			printf("Mile Juice %.0lf\n", M_ans);
	}
	return 0;
}
