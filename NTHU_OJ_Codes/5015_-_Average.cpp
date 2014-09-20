#include<stdio.h>

int main(){
	int t, n, i, x, f;
	while(scanf("%d", &t) > 0)
		while(t--){
			double tot = 0;
			scanf("%d%d", &n, &f);
			for(i = 0; i < n; i++)
				scanf("%d", &x), tot += x;
			switch(f){
				case 0:
					printf("%.0lf\n", tot / n);
					break;
				case 1:
					printf("%.1lf\n", tot / n);
					break;	
				case 2:
					printf("%.2lf\n", tot / n);
					break;	
				case 3:
					printf("%.3lf\n", tot / n);
					break;	
				case 4:
					printf("%.4lf\n", tot / n);
					break;	
				case 5:
					printf("%.5lf\n", tot / n);
					break;	
				case 6:
					printf("%.6lf\n", tot / n);
					break;	
				case 7:
					printf("%.7lf\n", tot / n);
					break;	
				case 8:
					printf("%.8lf\n", tot / n);
					break;	
				case 9:
					printf("%.9lf\n", tot / n);
					break;	
				case 10:
					printf("%.10lf\n", tot / n);
					break;	
				case 11:
					printf("%.11lf\n", tot / n);
					break;	
				case 12:
					printf("%.12lf\n", tot / n);
					break;	
			}
		}
	return 0;
}
