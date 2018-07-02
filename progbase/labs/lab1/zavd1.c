#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
float x = 0, y =0 , z = 0 ;
float a0 = 0, a1 = 0, a2 = 0;
float a = 0;
double n = (1/z);

printf("vvediti x=");
scanf("%f", &x);
printf("vvediti y=");
scanf("%f", &y);
printf("vvediti z=");
scanf("%f", &z);
	if (x == y || z == 0 || x == 0 || sin(y) == 0 || x < y){
		printf("немає розвязків");
		}

	else{
		a0 = pow(x, (y+1))/pow(x-y, n );
		a1 = 0 * y + (z/x);
		a2 = pow(x + 3, (1/fabs(sin(y))));
		a = a0 + a1 + a2;
			printf("%.10f\n", a);
			}

return 0;

}
