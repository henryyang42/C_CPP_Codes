#include<stdio.h>
#include<stdlib.h>
struct card{
	char kind;
	int value;	
}s[6];
typedef struct card D;
D cardof(char s[]){
	D ans;
	int i;
	ans.kind = s[0];
	for(i = 0; i < 13; i++)
		if("A23456789TJQK"[i] == s[1])
			ans.value = i + 1;
	return ans;
}
int sort_by_value(const void *v, const void *o){
	D *p1 = (D*)v, *p2 = (D*)o;
	if(p1 -> value != p2 -> value)
		return p1 -> value - p2 -> value;
	else
		return p1 -> kind - p2 -> kind;
}
int sort_by_kind(const void *v, const void *o){
	D *p1 = (D*)v, *p2 = (D*)o;
	if(p1 -> kind != p2 -> kind)
		return p1 -> kind - p2 -> kind;
	else
		return p1 -> value - p2 -> value;
}
int Four_of_a_Kind(){
	qsort(s, 5, sizeof(D), sort_by_value);
	if((s[0].value == s[1].value && s[1].value == s[2].value && s[2].value == s[3].value)
	|| (s[2].value == s[3].value && s[1].value == s[2].value && s[3].value == s[4].value))
		return 1;
	return 0;
}
int Full_House(){
	qsort(s, 5, sizeof(D), sort_by_value);
	if((s[0].value == s[1].value && s[1].value == s[2].value && s[3].value == s[4].value)
	|| (s[2].value == s[3].value && s[3].value == s[4].value && s[0].value == s[1].value))
		return 1;
	return 0;
}
int Flush(){
	if(s[0].kind == s[1].kind && s[1].kind == s[2].kind && s[2].kind == s[3].kind && s[3].kind == s[4].kind)
		return 1;
	return 0;
}
int Straight(){
	qsort(s, 5, sizeof(D), sort_by_value);
	if(s[0].value + 1 == s[1].value && s[1].value + 1 == s[2].value 
	&& s[2].value + 1 == s[3].value && s[3].value + 1 == s[4].value)  
		return 1;
	if(s[0].value == 1 && s[1].value == 10 && s[2].value == 11 && s[3].value == 12 && s[4].value == 13)
		return 1;
	return 0;
}
int Three_of_a_Kind(){
	qsort(s, 5, sizeof(D), sort_by_value);
	if((s[0].value == s[1].value && s[1].value == s[2].value)
	|| (s[2].value == s[3].value && s[3].value == s[4].value)
	|| (s[2].value == s[3].value && s[1].value == s[2].value))
		return 1;
	return 0;
}
int Two_Pairs(){
	qsort(s, 5, sizeof(D), sort_by_value);
	if((s[0].value == s[1].value && s[2].value == s[3].value)
	|| (s[0].value == s[1].value && s[3].value == s[4].value)
	|| (s[1].value == s[2].value && s[4].value == s[3].value))
		return 1;
	return 0;
}
int Pair(){
	qsort(s, 5, sizeof(D), sort_by_value);
	if(s[0].value == s[1].value || s[2].value == s[1].value
	|| s[2].value == s[3].value || s[3].value == s[4].value)
		return 1;
	return 0;
}
int main(){
	int i, t, ct = 0;
	char S[3];
	while(scanf("%d", &t) > 0)
		while(t--){
			for(i = 0; i < 5; i++)
				scanf("%s", S), s[i] = cardof(S);
			printf("Case #%d: ", ++ct);
			if(Straight() && Flush())
				puts("Straight Flush");
			else if(Four_of_a_Kind())
				puts("Four of a Kind");
			else if(Full_House())
				puts("Full House");
			else if(Flush())
				puts("Flush");
			else if(Straight())
				puts("Straight");
			else if(Three_of_a_Kind())
				puts("Three of a Kind");
			else if(Two_Pairs())
				puts("Two Pairs");
			else if(Pair())
				puts("Pair");
			else
				puts("Zilch");
		}
	return 0;
}
