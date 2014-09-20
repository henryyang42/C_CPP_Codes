#include<stdio.h>
#include<string.h>
int a,b,c,lapm[100],laps[100],tot[100],i,j,k,ave; char s[30];   
int main(){

    while(scanf("%s",s)>0){for(i=0,c=0;i<strlen(s);i++)if(s[i]<=122&&s[i]>=97) c+=s[i]-96;else c+=s[i]-38;
     
     for(a=0,i=2;i<c;i++) if(c%i==0) a++;
      if (a==0) printf("It is a prime word.\n");
      else printf("It is not a prime word.\n");

                    
                    
                    }
    
    

return 0;
}
