#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct data{
	struct data* next;
	char *p;	
}D;
D *root, *curr, *prev;
void insert(char temp[]){
	curr = (D*) malloc(sizeof(D));
	curr -> next = 0;
	curr -> p = (char*) malloc(sizeof(char) * (strlen(temp) + 1));
	strcpy(curr -> p, temp);
	if(root == 0)
		root = curr;
	else{
		curr -> next = root;
		root = curr;	
	}
}
void find(int n){
	int flag = n;
	curr = root;
	while(--n)
		prev = curr, curr = curr -> next;
	printf("%s", curr -> p);
	if(flag > 1){
		prev -> next = curr -> next;
		curr -> next = root;
		root = curr;
	}
}
void print(){/*debug*/
	curr = root;
	while(curr != NULL)
		 printf("%s ", curr -> p),curr = curr -> next;
	putchar(10);
}
int issame(char temp[]){
	curr = root;
	while(curr != 0){
		if(strcmp(curr -> p, temp) == 0)
			return 1;
		curr = curr -> next;	
	}
	return 0;
}
int main(){
	char c;
	while((c = getchar()) != EOF){
		
		if(c == '0')
			return 0;
		if(isalpha(c)){
			char temp[100] = {0};
			int i = 0;
			while(isalpha(c))
				temp[i++] = c, putchar(c), c = getchar();
			if(!issame(temp))
				insert(temp);		
		}
		if(isdigit(c)){
			char temp[100] = {0};
			int i = 0;
			while(isdigit(c))
				temp[i++] = c, c = getchar();
			find(atoi(temp));
		}
		putchar(c);
	}
	return 0;
}
