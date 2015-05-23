#include<stdio.h>
#include<stdlib.h>
typedef struct BST{
	struct BST *small, *big;
	int num;
}BST;
BST *root, *prev, *curr, *temp;
void delete_(){
	if(root == NULL)
		return;
	if(root -> small == NULL){
		temp = root;
		root = temp -> big;
		free(temp);
	}
	else{
		temp = root;
		while(temp -> small)
			prev = temp, temp = temp -> small;
		prev -> small = temp -> big;
		free(temp);
	}
}
void insert_(){
	curr = (BST*) malloc(sizeof(BST));
	curr -> small = 0;
	curr -> big = 0;
	scanf("%d", &(curr -> num));
	if(root == NULL)
		root = curr;
	else{
		temp = root;
		while(temp != NULL)
			if(temp -> num > curr -> num){
				if(temp -> small)
					temp = temp -> small;
				else
					temp -> small = curr, temp = 0;
			}
			else{
				if(temp -> big)
					temp = temp -> big;
				else
					temp -> big = curr, temp = 0;
			}
	}
}
void print(){
	if(root == NULL)
		puts("null");
	else{
		temp = root;
		while(temp -> small)
			temp = temp -> small;
		printf("%d\n", temp -> num);
	}
}
int main(){
	char c;
	while(scanf("%c", &c) > 0)
		switch(c){
			case 'd':
				delete_();
				break;
			case 'i':
				insert_();
				break;
			case 't':
				print();
				break;
			case 'e':
				return 0;	
		}
	return 0;
}
