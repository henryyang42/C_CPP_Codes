#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
int s[1000], k, n, w, t, slash[1000];
int sl(long long page){
	int remain, i = n - 1;
	long long pre;
	for(remain = k-1; remain >= 0; remain--){
		pre = 0;
		while(remain <= i && pre + s[i] <= page)
			pre += s[i--];
		slash[remain] = i;
	}
	return i == -1;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		long long upper = 0, lower = 0, mid;
		for(int i = 0; i < n; i++)
			scanf("%d", &s[i]), upper += s[i];
		while(upper > lower){
			mid = (upper + lower) / 2;
			if(sl(mid))
				upper = mid;
			else
				lower = mid+1;
		}
		sl(upper);
		int ct = 0;
		for(int i = 0; i < n; i++){
			if(i)
				putchar(32);
			printf("%d", s[i]);
			if(ct +1 < k && slash[ct+1] == i)
				printf(" /"), ct++;
		}
		putchar(10);
	}
	return 0;
}
