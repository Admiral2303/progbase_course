#include <stdio.h>
#include <math.h>
#include <stdbool.h>
	int main(void)
{
	int a,b,c;
	int modmin = 0;
	int max = -1;
	int min = 999999;
	int sum2 =0;
	int mod =0;
	int step = 0; 
	int x = 0;
	int y = 0;
	
	printf("write a=");
	scanf("%i", &a);
	printf("write b=");
	scanf("%i", &b);
	printf("write c=");
	scanf("%i", &c);



	if (a < 0 && b < 0 && c < 0)
	{
		if (a < b)
			modmin = a;
		else 
			modmin = b;
		if (modmin < fabs(c))
			modmin = fabs(c); 

		sum2 = a + b + c - modmin;

		while (modmin % 2 == 0) {
			mod = modmin / 2;}
		if ((mod == 1 && sum2 > -256 ) || (fabs(sum2) > modmin && sum2 > -256))
			printf("result = True\n");
		else 
			printf("result = False\n");
	}
	{
		if (a < 0) { 
			step++; x = a;
			} 
		if (b < 0) {
			step++;
			if (x == a)
				 y = b;
			else x = b; }
		if (c < 0) {
			step++;
			if (x == a || x == b) 
					y = c;
			else x = c;}

		if (step == 1)
			if(x > -256)
				printf("result = True\n");
			else
				printf("result = False\n");
		if (step == 2)
			if(3*(x+y) > -256)
				printf("result = True\n");
			else 
				printf("result = False\n");
	}
	if (a >= 0 && b >= 0 && c >= 0){
		if (max < a) max = a;
		if (max < b) max = b;
		if (max < c) max = c;
		
		if (min > a) min = a;
		if (min > b) min = b;
		if (min > c) min = c;

		if((max - min) > 32)
			printf("result = True\n");
		else 
			printf("result = False\n"); 
	}
	return 0;
}
