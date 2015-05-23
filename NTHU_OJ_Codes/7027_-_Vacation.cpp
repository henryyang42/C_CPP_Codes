#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 101

int a,b,c,d,e,f,g,i,j,l1,l2,ct,ans,k;
char s1[N], s2[N];int array[N][N]={0},prev[N][N];
int main(){
	ct = 0;
   while(gets(s1)>0){
		if(strcmp(s1,"#")==0) return 0;
		gets(s2);
		ct++;
		memset(prev,0,sizeof(prev));
		memset(array,0,sizeof(int)*N*N);
		l1=strlen(s1);l2=strlen(s2);
		for(i=0;i<l1;i++)
			for(j=0;j<l2;j++){
				if(s1[i]==s2[j])	
					array[i+1][j+1]=array[i][j]+1,prev[i][j]=1;
				else
					array[i+1][j+1]=array[i][j+1]>array[i+1][j]?array[i][j+1]:array[i+1][j];	
			}
			
			printf("Case #%d: you can visit at most %d cities.\n",ct,array[l1][l2]);
			
	}
    return 0;
}
