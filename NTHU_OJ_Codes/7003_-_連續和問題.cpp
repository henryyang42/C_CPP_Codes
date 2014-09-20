#include<stdio.h>
#include<stdlib.h>
int s[500000];
int main(){
	int t;
	while(scanf("%d", &t) > 0)
		while(t--){
			int n, x, i, temp, j;
			scanf("%d%d", &n, &x);
			for(i = 0; i < n; i++)
				scanf("%d", &s[i]);	
			for(i = 0; i < n; i++){
				temp = 0;
				j = i;
				do{
					temp += s[j++];
				}while(temp < x && j < n);
				if(temp == x)
					break;
			}
			if(i == n)
				puts("No");
			else
				puts("Yes");
		}
	return 0;
}
