// collaborated with Leandra McPhie and Sumayyah Husain
#include <stdio.h>
#include <stdlib.h>
 
/* IMPLEMENT ME: Declare your functions here */
typedef int (*Operation) (int a, int b);
int add (int a, int b);
int subtract (int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

 
int main (void)
{
  Operation operations[5];
  char operation[10];
  int op;
  operations[0] = add;
  operations[1] = subtract;
  operations[2] = multiply;
  operations[3] = divide;
  
	int a = 6;
	int b = 3;
	int result;
	while(1){
			printf("Operand 'a' : %d | Operand 'b' : %d \n Specify the operation to perform \n(0 : add | 1 : subtract | 2 : Multiply | 3: divide | 4 : exit): ", a, b);
			scanf("%s", operation);
			op = atoi(operation);
		while (op > 4) {
			printf("Specify the operation to perform\n(0 : add | 1 : subtract | 2 : Multiply | 3: divide | 4 : exit): ");
			scanf("%s", operation);
			op = atoi(operation);
		}


		if (op == 4){ 
			break; 
		}

		result = (*operations[op])(a, b);
		printf("x = %d\n", result);
 }
 
 return 0;
}
 
/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding 'a' and 'b'\n"); return a + b;}
int subtract (int a, int b) { printf ("Subtracting 'b' from 'a'\n"); return a - b;}
int multiply (int a, int b) { printf ("Multiplying 'a' and 'b'\n"); return a * b;}
int divide (int a, int b) { printf ("Dividing 'a' by 'b'\n"); return a / b;}

