#include<stdio.h>
#include<string.h>
int tail;
char pre[30],in[30];
void print(int begin,int end){
    int i;
    if(begin > end) return;
	tail++;
	for(i=0; in[i] != 0; i++)
		if(pre[tail] == in[i]){
			print(begin, i - 1);
			print(i + 1, end);
			putchar(in[i]);
			break;
		}
}
int main(){
	while(scanf("%s%s", pre, in) > 0){
		tail = -1;
		print(0, strlen(in) - 1);
		putchar(10);
	}
 return 0;
}
