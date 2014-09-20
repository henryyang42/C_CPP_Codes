#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define N 50001

int a,b,c,d,e,f,g,h,i,j,ans,max,l,len,k, pos;
char s[N*2]={0},ss[N];

int main(){
	while(scanf("%s",ss)>0){
			l=strlen(ss);
			for(i=0;i<l;i++)
				s[i*2]=ss[i];
			for(max=0,i=0;i<l*2;i++){
				if(s[i]!=0){
					len=1;k=1;
					while(s[i-k]==s[i+k]&&i-k>=0&&i+k<l*2){
						if(s[i-k]!=0)
							len+=2;
						k++;
					}
				}
				else{
					len=0;k=1;
					while(s[i-k]==s[i+k]&&i-k>=0&&i+k<l*2){
						if(s[i-k]!=0)
							len+=2;
						k++;
					}
				}
				if(len>max)
					max=len, pos = i;

			}
			if(max % 2)
				for(i = pos - 2 * (max / 2); i <= pos + 2 * (max / 2); i+= 2)
					putchar(s[i]);
			else
				for(i = pos - 2 * (max / 2) + 1; i <= pos + 2 * (max / 2) - 1; i+= 2)
					putchar(s[i]);
			putchar(10);


		}
	return 0;
}
