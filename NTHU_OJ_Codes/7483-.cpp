#include<stdio.h>
#include<stdlib.h>
int compare(const void*v, const void *o){
	return *(int*)v - *(int*)o;	
}
int main(){
	int t = 0;
	while(scanf("%d", &t) > 0)
		while(t--){
			int s[3], i, j, temp;
			scanf("%d%d%d", s, s + 1, s + 2);
			qsort(s, 3, sizeof(int), compare);
			if(s[0] + s[1] <= s[2])
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
