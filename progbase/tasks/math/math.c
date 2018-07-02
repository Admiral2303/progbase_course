#include <stdio.h>
#include<math.h>
int main(void) {
	double x = 0.0;
	double f = 0.0;
	double z = 0.0;
	double sum = 0.0;
	double mul = 0.0;
	double dev = 0.0;
	double dev2 = 0.0;
	

	for(x=-10; x<=10 ;x = x + 0.5){
	f = -(pow(x, 2)) + 3;
	z = 0.5 * tan(x + 2);
	sum = f + z;
	mul = f * z;
	dev = f / z;
	dev2 = z / f;
	
	printf("x=%.1f\n", x);
	printf("F1(%.1f)=%f\n", x , f);
	printf("F2(%.1f)=%f\n", x , z);
	printf("F1(%.1f)+F2(%.1f)=%f\n", x, x, sum);
	printf("F1(%.1f)*F2(%.1f)=%f\n", x, x, mul);
	
	if (z != 0)
		printf("F1(%.1f)/F2(%.1f)=%f\n", x, x, dev);
	else
		printf("F1(x) / F2(x) Division by zero\n");
	if (f !=0)
		printf("F2(%.1f)/F1(%.1f)=%f\n", x, x, dev2);
	else 
		printf("F2(x) / F1(x) Division by zero\n");
	
	
	}
	
	
	
	return 0;
}
