#include<cstring>
#include<cstdio>

int s[5], mul[101], ct;
unsigned short hash[25000100];
int main(){
	for(int i = 0; i <= 100; i++)
		mul[i] = (i-50)*(i-50)*(i-50);
	while(scanf("%d%d%d%d%d", s, s+1, s+2, s+3, s+4) > 0){
		memset(hash, 0, sizeof(hash));
		for(int i = -50; i <= 50; i++){
			if(!i) continue;
			for(int j = -50; j <= 50; j++){
				if(!j) continue;
				hash[s[3]*mul[i+50]+s[4]*mul[j+50]+12500010]++;
			}
		}
		unsigned long long ans = 0;
		for(int i = -50; i <= 50; i++){
			if(!i) continue;
			for(int j = -50; j <= 50; j++){
				if(!j) continue;
				for(int k = -50; k <= 50; k++){
					if(!k) continue;
					int x = -(s[0]*mul[i+50]+s[1]*mul[j+50]+s[2]*mul[k+50])+12500010;
					if(x >= 0 && x < 25000100)
					ans += hash[x];
				}
			}
		}
		printf("Case %d: %llu\n",++ct, ans);
	}
	return 0;
}
