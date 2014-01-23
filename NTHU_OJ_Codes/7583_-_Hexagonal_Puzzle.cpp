#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct puzzel{
	int s[6], i;
	bool operator < (puzzel &x)const{
		return x.i > i;
	}
}P;
void spin(P *x){
	int temp = x -> s[0];
	for(int i = 1; i < 6; i++)
		x -> s[i-1] = x -> s[i];
	x -> s[5] = temp;
}
P p[7];
int judge(){
	for(int k = 0; k < 7; k++){
		P pivot = p[k], temp[6];
		for(int j = 0, ct = 0; j < 7; j++)
			if(j != k)
				temp[ct++] = p[j];
		do{
				for(int i = 0; i < 6; i++){
					while(pivot.s[i] != temp[i].s[3])
						spin(&temp[i]);
				}
				int fg = 1;
				for(int i = 0; i < 6; i++){
					if(temp[(i+5) % 6].s[2] != temp[i].s[4] || temp[(i+1) % 6].s[4] != temp[i].s[2])
						fg = 0;
				}
				if(fg == 1)
					return 1;
		}while(next_permutation(temp, temp+6));
	}
	return 0;
}

int main(){
	while(scanf("%d%d%d%d%d%d", &p[0].s[0], &p[0].s[1], &p[0].s[2], &p[0].s[3], &p[0].s[4], &p[0].s[5]) > 0){
		for(int i = 0; i < 7; i++)
			p[i].i = i;
		for(int i = 1; i < 7; i++)
			for(int j = 0; j < 6; j++)
				scanf("%d", &p[i].s[j]);
		if(judge())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
