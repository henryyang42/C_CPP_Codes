#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>
bool compare(const char & a, const char & b){
	if(tolower(a) == tolower(b)) 
		return a < b;
	
		return tolower(a) < tolower(b);
}
int main(){
	int t, l;
	char s[1000];
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		l = strlen(s);
		std::sort(s, s + l, compare);
		do{
			puts(s);	
		}while(std::next_permutation(s, s + l, compare));
	}
	return 0;
}
