#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void *v, const void *o){
	return *(char*) o - *(char*) v;	
}
int compare2(const void *v, const void *o){
	return *(char*) v - *(char*) o;	
}
char s[10000], temp;
int main(){
	while(scanf("%s", s) > 0){
		int  i, j, flag = 0;
		double max, min;
		qsort(s, strlen(s), sizeof(char), compare);
		max = atof(s);
		j = strlen(s) - 1;
		while(s[j] == '0')
			j--, flag = 1;
		for(i = 0; i < j; i++, j--)
			temp = s[i], s[i] = s[j], s[j] = temp;
		if(flag)
			qsort(s + 1, strlen(s) - 1, sizeof(char), compare2);
		min = atof(s);
		printf("%.0lf - %.0lf = %.0lf = 9 * %.0lf\n", max, min, max - min, ( max - min) / 9);
	}
	return 0;
}
