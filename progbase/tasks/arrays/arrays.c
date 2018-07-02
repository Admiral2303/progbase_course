#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pbconsole.h>
#include <math.h>

int main(void)
{

	int A[10];
	int i = 0;
	int random = 0;
	int n =0;
	double sum = 0;
	double seredne = 0;
	int index = 0;
	int min = 0;
	int max = 0;
	char S[10];


	printf("zavd 1\n");
	srand(time(0));
	for (i = 0; i <= 9; i++){
		random = rand() %298 -99;
		A[i] = random;
		printf("  %i ", random);
	}
	printf("\n");
	printf("zavd 2\n");
	for (i = 0; i <= 9; i++){
		if(A[i] < 127 && A[i] > -99){
			conSetAttr(FG_GREEN);
			printf("  %i ",A[i]);
			conReset();
		}
		else{
			printf("  %i ",A[i]);
	}
	}
	printf("\nzavd3\n");
	for (i = 0; i <= 9; i++){
		if(A[i] < 50 && A[i] > -99){
			n++;
			sum += A[i];
			seredne = sum / n;
			conSetAttr(FG_RED);
			printf("  %i ",A[i]);
			conReset();
		}
		else{
			printf("  %i ",A[i]);
		}
	}
	printf("\n");
	printf("quantity = %i\n", n);
	printf("sum = %f\n", sum);
	printf("seredne = %f\n", seredne);

	printf("\nzavd 4");
	min = 200;
	for (i = 0; i <= 9; i++){
		if(A[i] < min){
			min = A[i];
			index = i;
		}
	}
	printf("\nindex min = %i\n", index);
	printf("\n");
	printf("zavd 5");
	max = -100;
	for (i = 0; i <= 9; i++){
		if(A[i] > max && A[i] < 0){
			max = A[i];
			index = i;
		}
	}
	printf("\nindex max = %i\n", index);
	printf("\nzavd 6");
	for (i = 0; i <= 9; i++){
		if (i==9){
			S [9] = '\0';
		}
		else{
			S[i]= (abs(A[i]) % 95) + 32;
		}
}
	printf("\n");
	puts( S);
	printf("\nzavd 7\n");
	for (i = 0; i <= 9; i++){
		if(A[i] > -25){
			A[i]=0;
			conSetAttr(FG_BLUE);
		}
		printf(" %i ",A[i]);
		conReset();
	}
	return 0;
}

