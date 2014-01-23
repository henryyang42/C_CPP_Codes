#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1


 int a,b,c,d,i,j=1,ascii[256],ans;char s[1001], tag = 0;

int main(){
    
    
    while(gets(s)>0){for(i=0;i<=256;i++)ascii[i]=0;
    if(tag++)putchar(10);
    for(i=0;i<strlen(s);i++)ascii[s[i]]++;
    for(j=1;j<=1000;j++)
    for(i=256;i>=0;i--)if(ascii[i]==j)printf("%d %d\n",i,ascii[i]);
                                 
                                 
                                 
                                 }
    
    
    return 0;
}
