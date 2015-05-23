#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 2600

char s[1001][N+1],n[1001];int a,b,c,d,i,k,j,tot[N+1],ans[N],tot2[12534];
    int main(){
      
      tot[N]=1;
      
               
               for(i=1;i<=1000;i++){
         
                    for(j=0;j<=N;j++)tot[j]*=i; 
                    for(j=N+1;j>=0;j--){tot[j]+=tot[j+1]/10;tot[j+1]%=10;} 
                    for(j=0;j<=N;j++)s[i][j]=tot[j];
                    
                    }
                   
                       
     
      
      while(scanf("%d",&a)>0){
          for(i=0;i<=N;i++)if(s[a][i]>0) break;
          for(j=i;j<=N;j++)printf("%d",s[a][j]);
          printf("\n");
            
             
      
        
        }
                                 
        
                        return 0;}
