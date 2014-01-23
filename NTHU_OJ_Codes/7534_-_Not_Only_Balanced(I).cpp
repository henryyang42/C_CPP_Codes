#include<stdio.h>
int returnvalue(char c){
	switch(c){
		case '{':
			return 1;
		case '[':
			return 2;
		case '(':
			return 3;
		case '<':
			return 4;
		case '}':
			return 5;
		case ']':
			return 6;
		case ')':
			return 7;
		case '>':
			return 8;
		default:
			return 0;
	}
}
int main(){
	int a, i, j, cti = 0;
	char s[3001];
	while(gets(s) > 0){
			cti++;
			char ct[3001] = {0}, fg = 1, top = 0;
			j = 0;
			while(s[j]){
				int ret = returnvalue(s[j]);
				if(ret > 4){
					int k;
					if(ct[top - 1] != ret - 4){
						fg = 0;
						break;
					}
					else
						top--;
					j++;
					continue;
				}
				if(!ret){
					j++;
					continue;
				}
				else{
					if(ct[top - 1] > ret){
						fg = 0;
						break;
					}

					ct[top++] = ret;
					j++;
				}
			}
			if(fg && !top){
				puts("Valid");
			}
			else
				puts("Invalid");
		}
    return 0;
}
