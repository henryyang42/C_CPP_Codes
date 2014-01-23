#include<stdio.h>
#include<stdlib.h>
int compare(const void*v, const void *o){
	return *(long long int*)v - *(long long int*)o;	
}
int main(){
	int t = 0;
	while(scanf("%d", &t) > 0)
		while(t--){
			long long int s[3], i, j, temp;
			scanf("%lld%lld%lld", s, s + 1, s + 2);
			qsort(s, 3, sizeof(long long int), compare);
			if(s[0] + s[1] <= s[2] || s[0] <= 0 || s[1] <= 0 || s[2] <= 0)
				puts("Oh~NO!!");
			else if(s[0] == s[1] && s[1] == s[2])
				puts("3 equal");
			else if(s[0] == s[1] || s[1] == s[2])
				puts("2 equal");
			else
				puts("OK!");	
		}
	return 0;
}
