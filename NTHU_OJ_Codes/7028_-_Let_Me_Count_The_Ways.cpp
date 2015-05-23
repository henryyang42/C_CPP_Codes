#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 30001
int a,b,c,d,e,f,g,h,i,j,k,l,tot;
unsigned long long int s[6][N];

int main(){
	for(i=0;i<N;i++)
		s[0][i]=1;
	for(i=0;i<N;i++){
		for(j=0;j<=i;j+=5)
			s[1][i]+=s[0][i-j];	
	}
	for(i=0;i<N;i++){
		for(j=0;j<=i;j+=10)
			s[2][i]+=s[1][i-j];	
	}
	for(i=0;i<N;i++){
		for(j=0;j<=i;j+=25)
			s[3][i]+=s[2][i-j];	
	}
	for(i=0;i<N;i++){
		for(j=0;j<=i;j+=50)
			s[4][i]+=s[3][i-j];	
	}
	while(scanf("%d",&a)>0){
		if(s[4][a] != 1)
			printf("There are %llu ways to produce %d cents change.\n",s[4][a], a);
		else
			printf("There is only 1 way to produce %d cents change.\n", a);
	}
	return 0;
}
