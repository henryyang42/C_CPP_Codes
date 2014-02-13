#include<cstdio>
int ss[] = {
	168*8+22*22,
	168*8+22*68,
	168*8+22*46+22*68,
	168*8+21*(68+47*2),
	168*8+68*68-36};
int abs(int x){
	return x > 0 ? x : -x;
}
int main(){
	int n;
	char s[300];
	while(scanf("%d", &n), n){
		double tot = 0;
		for(int i = 0; i < n; i++){
			scanf("%s", s);
			for(int j = 0; j < n; j++)
				if(s[j] == '0')
					tot++;
		}
		int totct = (tot) / (n*n)*10000.0;
		int min = 1e9, ind = -1;
		for(int i = 0; i < 5; i++)
			if(min > abs(totct - ss[i]))
				min = abs(totct - ss[i]), ind = i;
		printf("%d\n", ind+1);
	}
	return 0;
}
