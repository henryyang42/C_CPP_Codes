#include<stdio.h>
int main(){
	int a,b,i,j;
	while(scanf("%d%d",&a,&b)>0,a+b){
		double ans = 1;
		if(a-b<b)
			b=a-b;
		for(i=1;i<=b;i++)
			ans*=a-i+1,ans/=i;
		printf("%.0lf\n",ans);
	}
	return 0;
}

