#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct data{
	char c;
	int tag;	
}s[26];
int compare(const void*v, const void*o){
	struct data *p1 = (struct data*)v, *p2 = (struct data*)o;
	if(p2 -> tag != p1 -> tag)
		return p2 -> tag - p1 -> tag;
	else
		return p1 -> c - p2 -> c; 
}
int main(){
	char c, i;
	for(i = 0; i < 26; i++)
		s[i].c = i + 'a', s[i].tag = 0;
	while((c = getchar()) != EOF)
		if(islower(c))
			s[c - 'a'].tag += c - 'a' + 1;
	qsort(s, 26, sizeof(struct data), compare);
	for(i = 0; i < 26; i++)
		if(s[i].tag)
			printf("%c %d\n", s[i].c, s[i].tag);
	getchar();
	return 0;
}
