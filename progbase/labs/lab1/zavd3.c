#include<stdio.h>
#include<math.h>

int main(void)
{
	int a = 0;
	int b = 0;
	int op = 0;
	int temp = 0;
	int c = 0;
	int min = 0;
	int max = 0;
	int power = 0;
	double var = 0;
	int def = 0;


	printf("write a=");
	scanf("%i", &a);
	printf("write b=");
	scanf("%i", &b);
	printf("write op=");
	scanf("%i", &op);
	if (op < 0){
		temp = a;
		b = temp;
		a = b;
		op = fabs(op);
		}

	switch(op)
	{
		case 0:
			printf("a + b = %i\n", a + b);
			break;
		case 1:
			printf("a - b = %i\n", a - b);
				break;
		case 2:
			printf("a * b = %i\n", a * b);
		break;
		case 3:
		if (b != 0){
				printf("a / b = %i\n", a / b);
			}
			else{ 
				printf("divizion by zero\n");
			}
		break;
		case 4:
			printf("abs(a) = %f\n", fabs(a));
				break;
		case 5:
			if (a < b){
				min = a;
					printf("min = %i\n", min );
					}
			else{
				min = b;
					printf("min = %i\n", min);
					}
		break;
		case 6:
			if (a < b){
				max = b;
					printf("max = %i\n", max);}
			else{
				max = a;
					printf("max = %i\n", max);}
		break;
		case 7:
			power = pow(a, b);
				printf("pow(a,b) = %i\n", power);
		break;
		case 13:
			power = pow(a, b);
				printf("pow(a,b) = %i\n", power);
		break;
		case 8:
			if (b != 0){
				var = (double)(tan ((double)a * 3.14))/ (double)(0 - 4 * (double)b);
					printf("var(a,b) = %.10f\n", var);
				}
				else{
					printf("devizion by zero\n");
				}
		break;
		default:
		c = fabs(a + 1);
		if ( a != -1 && b != -1){
			def = ((op % c) + (op % c));
				printf ("def( a, b) = %i\n", def);
			}
		else{ 
			printf("devizion by zero\n");
			}
		break;
	}

	return 0;

}

