#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a,b,c,d=0,e,i,j,prime[1000000],r[200000], ct = 0; 
int main(){
    prime[1]=1;
    
    for(i=2;i<=1000000;i++)if(prime[i]==0){ r[d]=i;d++; for(j=2*i;j<=1000000;j+=i) prime[j]=1;}
    
    
    
    while(scanf("%d",&a)>0){if(a==0) return 0;
    


if(a>1000000){
	int sqrt_a = sqrt(a);
for(i=0,c=0;r[i]<=sqrt_a;i++){if(a%r[i]==0){c++;break;} }
if(c)
printf("Case #%d: NO\n", ++ct);
else
	printf("Case #%d: YES\n", ++ct);
} 


else{
	    if(prime[a] == 1)
	    	printf("Case #%d: NO\n", ++ct);
	    	else
	    	printf("Case #%d: YES\n", ++ct);
						}
                           
                                 
                                 
                                 
                                 
                                 
                                 
                                 
                                 
                            
                            
                            
                            
                            
                            
                            } /*while*/
    
    
    
return 0;
}
