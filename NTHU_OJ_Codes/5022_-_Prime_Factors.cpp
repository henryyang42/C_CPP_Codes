#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int b,c,d,i,j,k;int prime[46341],rprime[4792];long long a;
int main(){
    for(i=2;i<46341;i++){if(prime[i]==0){rprime[c++]=i;for(j=2*i;j<46341;j+=i)prime[j]=1;}}
    
    
while(scanf("%lld",&a)>0){if(a==0) return 0;
                        
                        printf("%lld =",a);
                        
                        if(a<0){ a=-a;printf(" -1 x");}
                        int  tag = 0;
                        b=a;
                        int sqrt_b = sqrt(b);
                        for(i=0;rprime[i]<= sqrt_b&&a!=1;i++){
                                         while(a%rprime[i]==0){a/=rprime[i];printf(" %d",rprime[i]);
										 if(a!=1)printf(" x");else break;}}
                                         
                                         if(a>1) printf(" %lld",a);
                                         
                                         printf("\n");

                        
                        
                        
                        
                        
                        
                        }
                        return 0;}
