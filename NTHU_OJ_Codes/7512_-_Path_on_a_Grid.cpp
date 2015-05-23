#include<stdio.h>
int main(){
	int i,j;
	unsigned long long int a, b, c;
	while(scanf("%llu%llu",&a,&b)>0,a+b){
		double ans = 1;
		if(b > a)
			c = b, b = a, a = c;
		b = a > b ?b : a;
		a = a + b;
		if(a-b<b)
			b=a-b;
		for(i=1;i<=b;i++)
			ans*=a-i+1,ans/=i;
		printf("%.0lf\n",ans);
	}
	return 0;
}

