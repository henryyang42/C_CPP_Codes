#include<stdio.h>

int main(){
	int n, i;
	while(scanf("%d", &n) > 0){
		for(i = 0; i < 32; i++)
			if(!(n >> i))
				break;
		printf("%d\n", i);
	}
	return 0;
}
