#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n, s[21];
	while(scanf("%d", &n), n){
		int sum = 0, Min = 1e9, temp;
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i]), sum += s[i];
		for(int i = 0; i < (1<<n); i++){
			temp = 0;
			for(int j = 0; j < n; j++)
				if((i >> j) & 1)
					temp += s[j];
			Min = min(Min, abs(2*temp - sum));
		}
		printf("%d\n", Min);
	}
	return 0;
}
