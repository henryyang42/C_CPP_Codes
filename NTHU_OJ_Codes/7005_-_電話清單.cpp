#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int checkn;
struct data{
	char s[11];
	int l;
}data[10001];
int compare(const void *v, const void *o){
	struct data *s1 = (struct data*)v, *s2 = (struct data*)o;
	int i = 0;
	while(s1 -> s[i] == s2 -> s[i] && s1 -> s[i] && s2 -> s[i])
		i++;
	if(s1 -> s[i] == 0 || s2 -> s[i] == 0)
		checkn = 0;
	return s1 -> s[i] - s2 -> s[i];
}
int main(){
	int t;
	while(scanf("%d", &t) > 0)
		while(t--){
			int i, n;
			scanf("%d", &n);
			for(i = 0; i < n; i++)
				scanf("%s", data[i].s);
			checkn = 1;
			qsort(data, n, sizeof(struct data), compare);
			if(checkn)
				puts("YES");
			else
				puts("NO");
		}
	return 0;
}
