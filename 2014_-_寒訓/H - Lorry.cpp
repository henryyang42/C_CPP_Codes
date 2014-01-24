/*PH Test*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int Vehicles, Capacity;
int Type, Value;
int Vehicle[2][120000][2];/*Type: Value, ID*/
int Max[4];
int VCount[4];
int i, x, y, c, Ans, Printed;
long long FAns;
int se[120000], se_ct;
int QS(const void *v, const void *o){
	int *A = (int*)v, *B = (int*)o;
	for (c=0; c<2; c++){
		if (A[c]>B[c]) return -1;
		if (A[c]<=B[c]) return 1;
	}
	return 0;
}

int main(){
	while(~scanf("%d%d", &Vehicles, &Capacity)){
		memset(Vehicle, 0, sizeof(Vehicle));
		memset(Max, 0, sizeof(Max));
		FAns = 0;
		Printed = 0;
		se_ct = 0;
		for (i=0; i<Vehicles; i++){
			scanf("%d%d", &Type, &Value);
			Vehicle[Type-1][Max[Type-1]][0] = Value;
			Vehicle[Type-1][Max[Type-1]][1] = i+1;
			Max[Type-1]++;
		}
		for (i=0; i<2; i++){
			qsort(Vehicle[i], Max[i], sizeof(Vehicle[0][0]), QS);
			Vehicle[i][Max[i]][0] = 0;
			Vehicle[i][Max[i]+1][0] = 0;
			VCount[i] = 0;

		}

		while(Capacity){
			if(VCount[0]>=Max[0] && VCount[1]>=Max[1])
				break;
			if (Capacity==1){
				FAns += Vehicle[0][VCount[0]][0];
				se[se_ct++] = Vehicle[0][VCount[0]][1];
				VCount[0]++;
				Capacity -= 1;

				continue;
			}
			if (VCount[0]>=Max[0]){
				FAns += Vehicle[1][VCount[1]][0];
				se[se_ct++] = Vehicle[1][VCount[1]][1];
				VCount[1]++;
				Capacity -= 2;

				continue;
			}
			if (VCount[1]>=Max[1]){
				FAns += Vehicle[0][VCount[0]][0];
				se[se_ct++] = Vehicle[0][VCount[0]][1];
				VCount[0]++;
				Capacity -= 1;
				continue;
			}

			if (Vehicle[1][VCount[1]][0] > (Vehicle[0][VCount[0]][0]+Vehicle[0][VCount[0]+1][0])){
				FAns += Vehicle[1][VCount[1]][0];
				se[se_ct++] = Vehicle[1][VCount[1]][1];
				VCount[1]++;
				Capacity -= 2;
			}
			else{
				FAns += Vehicle[0][VCount[0]][0];
				se[se_ct++] = Vehicle[0][VCount[0]][1];
				VCount[0]++;
				Capacity -= 1;
			}
		}

		printf("%lld\n", FAns);
		/*for (i=0; i<2; i++){
			for (x=0; x<VCount[i]; x++){
				if (Printed) putchar(32);
				else Printed = 1;
				printf("%d", Vehicle[i][VCount[x]][1]);
			}
		}*/
		if(FAns){
			for(int i = 0; i < se_ct; i++){
				if(i)
					putchar(32);
				printf("%d", se[i]);
			}
			putchar(10);
		}
	}

	return 0;
}

