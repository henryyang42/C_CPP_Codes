#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int c[3], coor[3][8], min_[3], max_[3];
		double c_[3], r, d, temp = 0;
		for(int i = 0; i < 8; i++)
			scanf("%d%d%d", &coor[0][i], &coor[1][i], &coor[2][i]);
		scanf("%d%d%d%lf", &c[0], &c[1], &c[2], &r);
		for(int i = 0; i < 3; i++){
			min_[i] = 1e9, max_[i] = -1;
			for(int j = 0; j < 8; j++){
				min_[i] = min(min_[i], coor[i][j]);
				max_[i] = max(max_[i], coor[i][j]);
			}
		}
		for(int i = 0; i < 3; i++){
			if(min_[i] <= c[i] && max_[i] >= c[i])
				c_[i] = c[i];
			else if(min_[i] > c[i])
				c_[i] = min_[i];
			else
				c_[i] = max_[i];
			temp += (c_[i] - c[i]) * (c_[i] - c[i]);
		}
		d = sqrt(temp);
		if(d > r)
			puts("No");
		else
			puts("Yes");
	}
	return 0;
}
