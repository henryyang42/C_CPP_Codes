#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 1010
int a,b,c,d,e,f,g,h,u,i,k,j,ct[MAX]={0};
unsigned long long int s[MAX][500/17]={0};

int main(){
	s[0][0]=0;
	s[1][0]=1;
	ct[0]=1;
	ct[1]=1;
	for(i=2;i<=MAX;i++){
		for(j=0;j<ct[i-1];j++)
			s[i][j]=s[i-1][j]+s[i-2][j];
		for(j=0;j<ct[i-1];j++){
			s[i][j+1]+=s[i][j]/1000000000000000000LL;
			s[i][j]%=1000000000000000000LL;
		}
		if(s[i][ct[i-1]]>0)
			ct[i]=ct[i-1]+1;
		else
			ct[i]=ct[i-1];
	}
	while(scanf("%d",&a)>0, a){
		printf("%lld",s[a][ct[a]-1]);
		for(i=ct[a]-2;i>=0;i--)
			printf("%018lld",s[a][i]);
		printf("\n");
	}

	return 0;
}
