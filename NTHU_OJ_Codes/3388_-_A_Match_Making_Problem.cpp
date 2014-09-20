#include<stdio.h>

int main(){
	int b, g, ct = 0, x;
	while(scanf("%d%d", &b, &g), b + g){
		int bb[100] = {0}, gg[100] = {0}, age = 60;
		for(int i = 0; i < b; i++)
			scanf("%d", &x), bb[x]++;
		for(int i = 0; i < g; i++)
			scanf("%d", &x), gg[x]++;
		while(b && g && age >= 2){
			if(bb[age] == 0){
				age--;
				continue;
			}
			for(int i = 0; ; i++){
				if((age + i) <= 60 && gg[age+i]){
					bb[age]--, gg[age+i]--;
					break;
				}
				if((age - i) >= 2 && gg[age-i]){
					bb[age]--, gg[age-i]--;
					break;
				}
			}
			b--, g--;
		}
		printf("Case %d: %d", ++ct, b);
		if(b){
			age = 2;
			while(bb[age] == 0)
				age++;
			printf(" %d", age);
		}
		putchar(10);
	}
	return 0;
}
