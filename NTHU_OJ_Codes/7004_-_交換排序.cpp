#include<stdio.h>

int main(){
	int s[1001];
	int i, j, a;
	while(scanf("%d",&a)>0){
		int ans = 0;
		for(i = 0; i < a; i++)
			scanf("%d",s+i);
		for(i = 0; i < a; i++)
			for(j = i; j < a; j++)
				if(s[i]>s[j])
			ans++;
		printf("Minimum exchange operations : %d\n",ans);
	}
	return 0;
}
