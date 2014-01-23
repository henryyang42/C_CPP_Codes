#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long int a,b,c,d,e,f,g,h,i,j,ii,jj,po[333];



int main(){
	while(scanf("%lld %lld %lld",&po[1],&b,&c)>0){
		
		for(i=2;i<=33;i++)
			po[i]=po[i-1]*po[i-1]%c;
		
		for(i=1,d=1;b>0;i++,b/=2){
			if(b%2==1) d*=po[i];
			d%=c;	
		}
		printf("%lld\n",d);
	}
	
	return 0;
}
