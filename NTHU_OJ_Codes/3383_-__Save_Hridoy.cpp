#include<stdio.h>
#include<string.h>
char temp[300][300];
char word[5][51] = {
"*****.***.*...*******...**************..******...*",
"*....*...**...**....*...**...*..*..*..*.*...*.*.*.",
"***********...****..**********..*..*...**...*..*..",
"....**...*.*.*.*....*...**.*....*..*..*.*...*..*..",
"******...*..*..******...**..**********..*****..*.."
};
char copy[5][100] = {
"*****..***..*...*.*****...*...*.*****.*****.***...*****.*...*",
"*.....*...*.*...*.*.......*...*.*...*...*...*..*..*...*..*.*.",
"*****.*****.*...*.***.....*****.*****...*...*...*.*...*...*..",
"....*.*...*..*.*..*.......*...*.*.*.....*...*..*..*...*...*..",
"*****.*...*...*...*****...*...*.*..**.*****.***...*****...*..",
};
void get_letter(int pos, int size){
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++){
			char x = word[i][5*pos + j];
			for(int k = 0; k < size; k++)
				for(int l = 0; l < size; l++)
					temp[i*size + k][j*size + l] = x;
		}
}
void print(int size){
	for(int i = 0; i < 5*size; i++, putchar(10))
		for(int j = 0; j < 5*size; j++)
			putchar(temp[i][j]);
}
void print_sep(int size){
	for(int i = 0; i < size; i++, putchar(10))
		for(int j = 0; j < 5*size; j++)
			putchar('.');
}
int main(){
	int n;
	while(scanf("%d", &n), n){
		if(n > 0){
			for(int l = 0; l < 5; l++)
				for(int i = 0; i < n; i++, putchar(10))
					for(int k = 0; k < 61; k++)
						for(int j = 0; j < n; j++)
							putchar(copy[l][k]);

		}
		else{
			get_letter(0, -n), print(-n), print_sep(-n);
			get_letter(1, -n), print(-n), print_sep(-n);
			get_letter(2, -n), print(-n), print_sep(-n);
			get_letter(3, -n), print(-n), print_sep(-n), print_sep(-n), print_sep(-n);
			get_letter(4, -n), print(-n), print_sep(-n);
			get_letter(5, -n), print(-n), print_sep(-n);
			get_letter(6, -n), print(-n), print_sep(-n);
			get_letter(7, -n), print(-n), print_sep(-n);
			get_letter(8, -n), print(-n), print_sep(-n);
			get_letter(9, -n), print(-n);
		}
		putchar(10);
		putchar(10);
	}
	return 0;
}
