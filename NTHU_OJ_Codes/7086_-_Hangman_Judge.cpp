#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int digit,a,b,c,d,e,f,g,h,j,i,k,l;



int main(){
	
	while(scanf("%d",&a)>0,a+1){
		char s[2000]={0},s2[2000]={0},n[270]={0},m[270]={0};
		int word=0,count=0;
		scanf("%s%s",s,s2);
		c=strlen(s);
		for(i=0;i<c;i++)
			n[s[i]]=1;
		for(i=1;i<=260;i++)
			word+=n[i];
		
		for(e=0,c=strlen(s2),f=0,i=0;i<c;i++){
			if(n[s2[i]]==1){
				word--;
				for(j=i+1;j<c;j++)
					if(s2[j]==s2[i])
						s2[j]=0;	
			}
			else if(n[s2[i]]==0&&s2[i]!=0){
			if(s2[i]>0)count++;
			for(j=i+1;j<c;j++)
					if(s2[j]==s2[i])
						s2[j]=0;		
			}
			if(word==0){
				printf("Round %d\nYou win.\n",a);
				break;	
			}
			if(count==7){
				printf("Round %d\nYou lose.\n",a);
				break;	
			}
			
			
		}
			
		if(count<7&&word>0)
				printf("Round %d\nYou chickened out.\n",a);
				
	}
	return 0;	
}
