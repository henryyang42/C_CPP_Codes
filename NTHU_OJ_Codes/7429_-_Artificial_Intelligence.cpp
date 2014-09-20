#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct data{
	int tag;
	double value;
}data[3];
int isdata(char s[]){
	if((s[0] == 'P' || s[0] == 'I' || s[0] == 'U')	&& s[1] == '=')
		return 1;
	return 0;
}
void verify(char s[]){
	int i = 0, j = 2;
	char temp[30] = {0};
	double value;
	while(isdigit(s[j]) || s[j] == '.')
		temp[i++] = s[j++];
	value = atof(temp);
	if(s[j] == 'm')
		value /= 1000.0;
	if(s[j] == 'M')
		value *= 1000000.0;
	if(s[j] == 'k')
		value *= 1000.0;
	switch(s[0]){
		case 'P':
			/*printf("P = %f\n", value);*/
			data[0].tag = 1;
			data[0].value = value;
			break;
		case 'I':
			/*printf("I = %f\n", value);*/
			data[1].tag = 1;
			data[1].value = value;
			break;
		case 'U':
			/*printf("U = %f\n", value);*/
			data[2].tag = 1;
			data[2].value = value;
			break;	
	}	
}
char s[10000];
int main(){
	int t, i, j, l, ct = 0;
	while(scanf("%d", &t) > 0){
		getchar();
		while(t--){
			data[0].tag = 0, data[1].tag = 0, data[2].tag = 0;
			gets(s);
			l = strlen(s);
			for(i = 0; i < l; i++){
				char temp[100] = {0};
				j = 0;
				while(s[i] != ' ' && s[i] != 10 && s[i] != 0)
					temp[j++] = s[i++];
				temp[j] = 0;
				if(isdata(temp))
					verify(temp);
			}
			printf("Problem #%d\n", ++ct);
			if(data[0].tag && data[1].tag)
				printf("U=%.2lfV\n", data[0].value / data[1].value);
			if(data[0].tag && data[2].tag)
				printf("I=%.2lfA\n", data[0].value / data[2].value);
			if(data[2].tag && data[1].tag)
				printf("P=%.2lfW\n", data[2].value * data[1].value);
			putchar(10);
		}
	}
	return 0;
}
