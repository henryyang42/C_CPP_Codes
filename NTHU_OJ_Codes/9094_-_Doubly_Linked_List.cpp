#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct doubly_linkedlist{
	int num;
	struct doubly_linkedlist *prev, *next;
}DL;
DL *head, *tail, *temp, *curr, *middle;
int tot = 0, headct = 0, tailct = 0, middlepos = 0;
void first(DL *ptr){
	head = ptr;
	tail = ptr;
	middle = ptr;
	middlepos = 0;
	tot = 1;	
}
DL *construct(int num){
	DL *ptr;
	ptr = (DL*) malloc(sizeof(DL));
	ptr -> num = num;
	ptr -> next = 0;
	ptr -> prev = 0;
	return ptr;	
}
void changemiddle(){
	if(tot == 1){
		middle = head;
		middlepos = 0;
		return;
	}
	while(middlepos > (tot / 2) - 1)
		middle = middle -> prev, middlepos--;
	while(middlepos < (tot / 2) - 1)
		middle = middle -> next, middlepos++;
}
void IH(int num){
	curr = construct(num);
	if(head == 0 || tail == 0){
		first(curr);
		headct++;
		return;
	}
	curr -> next = head;
	head -> prev = curr;
	head = curr;
	tot++;
	middlepos++;
	if(middlepos != tot / 2 - 1)
		changemiddle();
}
void IT(int num){
	curr = construct(num);
	if(head == 0 || tail == 0){
		first(curr);
		tailct++;
		return;
	}
	curr -> prev = tail;
	tail -> next = curr;
	tail = curr;
	tot++;
	if(middlepos != tot / 2 - 1)
		changemiddle();
}
void print(){
/*debug information*/
	puts("-------------------------");
	printf("middlepos:%d tot:%d\n", middlepos, tot);
	printf("middle:%d\n", middle -> num);
	puts("from head");
	curr = head;
	while(curr != 0)
		printf("%d ", curr -> num), curr = curr -> next;
	putchar(10);
	curr = tail;
	puts("from tail");
	while(curr != 0)
		printf("%d ", curr -> num), curr = curr -> prev;
	putchar(10);
	puts("-------------------------");	
}
void RH(){
	if(tot && !head){
		putchar(10);
		return;
	}
	printf("%d\n", head -> num);
	temp = head -> next;
	if(temp)
		temp -> prev = 0;
	else
		tail = head = 0;
	free(head);
	head = temp;
	tot--;
	middlepos--;
	if(tot == 1 ||(tot && middlepos != tot / 2 - 1))
		changemiddle();
}

void RT(){
	if(tot && !tail){
		putchar(10);
		return;
	}
	printf("%d\n", tail -> num);
	temp = tail -> prev;
	if(temp)
		temp -> next = 0;
	else
		tail = head = 0;
	free(tail);
	tail = temp;
	tot--;
	if(tot == 1 ||(tot && middlepos != tot / 2 - 1))
		changemiddle();
}

void SWAP(){
	if(tot %2 == 0){
		tail -> next = head;
		head -> prev = tail;
		temp = tail;
		tail = middle;
		head = middle -> next;
		head -> prev = 0;
		middle -> next = 0;
		middle = temp;
		return;
	}
	if(tot == 2){
		int temp = tail -> num;
		tail -> num = head -> num;
		head -> num = temp;
		return;	
	}
	tail -> next = head;
	head -> prev = tail;
	temp = tail;
	tail = middle;
	head = middle -> next;
	head -> prev = 0;
	middle -> next = 0;
	middle = temp -> prev;
}
int main(){
	char s[10];
	int num;
	while(scanf("%s", s) > 0){
		if(tot == 0 || middlepos == -1)
			middlepos = 0, middle = 0;
		if(strcmp(s, "IH") == 0){
			scanf("%d", &num);
			IH(num);
		}
		else if(strcmp(s, "IT") == 0){
			scanf("%d", &num);
			IT(num);
		}
		else if(strcmp(s, "RH") == 0){
			if(tot)
				RH();
			else
				putchar(10);
		}
		else if(strcmp(s, "RT") == 0){
			if(tot)
				RT();
			else
				putchar(10);
		}
		else if(strcmp(s, "S") == 0 && tot > 1){
			SWAP();
		}
		/*print();*/
	}
	return 0;
}
