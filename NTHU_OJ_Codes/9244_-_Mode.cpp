#include<stdio.h>
#include<string.h>
int ct[1001];
int main(){
	int i, a, n;
	while(scanf("%d",&n) > 0, n){
		memset(ct, 0, sizeof(ct));
		int  max = 0, maxi = 0;
		for(i = 0; i < n; i++)
			scanf("%d", &a), ct[a]++;
		for(i = 1; i <= 1000; i++)
			if(ct[i] > max)
				max = ct[i], maxi = i;
		printf("%d\n",maxi);
	}
    return 0;
}
