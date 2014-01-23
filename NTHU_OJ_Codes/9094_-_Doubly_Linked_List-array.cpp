#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int s[1000000];
int head = 500000, tail =500001, tot = 0;
void SWAP(int start, int end){
	head += (end - start + 1) / 2 - 1;
	int k = (end - start) / 2 - 1, i, j;
	if((end - start + 1) % 2==0)
	k++;
	for(i = 0; i < k; i++)
		s[tail++] = s[start + i+1];
}
void print(){
	int i;
	printf("head:%d tail:%d\n", head, tail);
	for(i = head + 1; i < tail; i++)
		printf("%d ", s[i]);
	putchar(10);	
}
int main(){
	char str[10];
	int num;
	while(scanf("%s", str) > 0){
		if(strcmp(str, "IH") == 0){
			scanf("%d", &num);
			/*if(head == tail)
				s[head--] = num, tail;
			else*/
			tot++;
				s[head--] = num;	
		}
		else if(strcmp(str, "IT") == 0){
			scanf("%d", &num);
		/*	if(head == tail)
				s[tail++] = num, head;
			else*/
			tot++;
				s[tail++] = num;
		}
		else if(strcmp(str, "RH") == 0 && tot){
			tot--;
			printf("%d\n", s[++head]);
		}
		else if(strcmp(str, "RT") == 0 && tot){
			tot--;
			printf("%d\n", s[--tail]);
		}
		else if(strcmp(str, "S") == 0){
			SWAP(head, tail);
		}
	print();
	}
	return 0;
}
