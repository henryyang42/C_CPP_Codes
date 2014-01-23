#include<stdio.h>
#include<map>
using namespace std;

int main(){
	long long a, b, c, d, e, ct = 0, ans;
	while(scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e) > 0){
		map<long long, long long> m2;
		map<long long, long long>::iterator it;
		for(int i = -50; i <= 50; i++){
			if(i == 0) continue;
			for(int j = -50; j <= 50; j++){
				if(j == 0) continue;
				for(int k = -50; k <= 50; k++){
					if(k == 0) continue;
					int x = c*i*i*i + d*j*j*j + e*k*k*k;
					if(m2.find(x) == m2.end())
						m2[x] = 1;
					else
						m2[x]++;
				}
			}
		}
		ans = 0;
		for(int i = -50; i <= 50; i++){
			if(i == 0) continue;
			for(int j = -50; j <= 50; j++){
				if(j == 0) continue;
				int x = a*i*i*i + b*j*j*j;
				ans += m2[x];
			}
		}
		printf("Case %lld: %lld\n", ++ct, ans);
	}
	return 0;
}
