#include<stdio.h>
char prime[1300001];
int p[130001], pct;
int main(){
	for(int i = 2; i < 1300000; i++)
		if(!prime[i]){
			for(int j = 2 * i; j < 1300000; j += i)
				prime[j] = 1;
			p[pct++] = i;
		}
	int n;
	while(scanf("%d", &n) > 0, n){
		if(!prime[n])
			puts("0");
		else{
			int low = 0, high = pct - 1, mid;
			while(low < high){
				mid = (low + high) / 2;
				if(n > p[mid])
					low = mid + 1;
				else
					high = mid - 1;
			}
			mid = (low + high) / 2;
			low = high = mid;
			while(p[low] > n)
				low--;
			while(p[high] < n)
				high++;
			printf("%d\n", p[high] - p[low]);
		}
	}
	return 0;
}

