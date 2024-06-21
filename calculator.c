#include<stdio.h>

int main(){
 char operator;
 double a, b, result;
 printf("Enter the operator (+, -, *, /): ");
 scanf("%c", &operator);
 printf("Enter both the numbers: ");
 scanf("%lf %lf", &a, &b);

 switch(operator){
	 case '+':
	  result = a +b;
	  break;
	 case '-':
	  result = a - b;
	  break;
	 case '*':
	  result = a * b;
	  break;
	 case'/':
	  if (b != 0){
	  result = a / b;
	  }else{
		printf("Error : division by zero");
	  }
	  break;

	 default:
	  printf("Error: invalid operator\n");
 }

 printf("%.2lf %c %.2lf = %.2lf\n", a, b, operator, result);
 return 0;
}

	
