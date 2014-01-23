#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int compare(const void*v, const void *o){
	double a = *(double*)v, b = *(double*)o;
	if(a > b)
		return 1;

	return -1;
}
double s[1000001];
int ct = 0;
int main(){
	double a2 = log10(2.0), a3 = log10(3.0), a5 = log10(5.0);
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			for(int k = 0; k < 100; k++)
				s[ct++] = a2 * i + a3 * j + a5 * k;
	qsort(s, ct, sizeof(double), compare);
	printf("The 1500'th ugly number is %.0lf.\n", pow(10, s[1499]));
	return 0;
}
