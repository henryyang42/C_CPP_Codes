#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct doubly_linkedlist{
	int num;
	struct doubly_linkedlist *prev, *next;
}DL;
DL *head, *tail, *temp, *curr, *root;
int tot = 0;

DL *construct(int num){
	DL *ptr;
	ptr = (DL*) malloc(sizeof(DL));
	ptr -> num = num;
	ptr -> next = 0;
	ptr -> prev = 0;
	return ptr;	
}

void first(DL *ptr){
//	root = construct(3);
	root -> next = ptr;
	root -> prev = ptr;
	tot = 1;	
}

void IH(int num){
	curr = construct(num);
	if(tot == 0){
		first(curr);
		tot++;
		return;
	}
	head = root -> next;
	curr -> next = head;
	head -> prev = curr;
	curr -> prev = root;
	head = curr;
	tot++;
}

void IT(int num){
	curr = construct(num);
	if(tot == 0){
		first(curr);
		tot++;
		return;
	}
	tail = root -> prev;
	curr -> prev = tail;
	tail -> next = curr;
	curr -> next = root;
	tail = curr;
	tot++;
}
void print(){
/*debug*/
	puts("-------------------------");
	puts("from head");
	curr = root -> next;
	while(curr != root)
		printf("%d ", curr -> num), curr = curr -> next;
	putchar(10);
	curr = root -> prev;
	puts("from tail");
	while(curr != root)
		printf("%d ", curr -> num), curr = curr -> prev;
	putchar(10);
	puts("-------------------------");	
}
void RH(){
	head = root -> next;
	if(!head)
		return;
	printf("%d\n", head -> num);
	temp = head -> next;
	if(temp)
		temp -> prev = 0;
	else
		tail = head = 0;
	free(head);
	head = temp;
	tot--;
}

void RT(){
	tail = root -> prev;
	if(!tail)
		return;
	printf("%d\n", tail -> num);
	temp = tail -> prev;
	if(temp)
		temp -> next = 0;
	else
		tail = head = 0;
	free(tail);
	tail = temp;
	tot--;
}

void SWAP(){
	int k = tot / 2 - 1;
	if(!head || !tail)
		return;
	temp = head;
	while(k-- && tot > 1)
		temp = temp -> next;
	head -> prev = tail;
	tail -> next = head;
	if(temp -> next)
		(temp -> next) -> prev = 0;
	head = temp -> next;
	temp -> next = 0;
	tail = temp;
}

int main(){
	char s[10];
	int num;
	root = construct(-1);
	while(scanf("%s", s) > 0){
		if(strcmp(s, "IH") == 0){
			scanf("%d", &num);
			IH(num);
		}
		else if(strcmp(s, "IT") == 0){
			scanf("%d", &num);
			IT(num);
		}
		else if(strcmp(s, "RH") == 0){
			RH();
		}
		else if(strcmp(s, "RT") == 0){
			RT();
		}
		else if(strcmp(s, "S") == 0){
			SWAP();
		}
		print();
	}
	return 0;
}
