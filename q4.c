#include<stdio.h>
#include<math.h>

//function to check if number is a perfect square
int isPerfectSquare(int x){
	int s = sqrt(x);
	return (s*s == x);
}

int main(){
 int n;
 printf("Enter a positive integer ");
 scanf("%d", &n);

 if(n<=0){
  printf("Please enter a positive integer.\n");
  return 1;
 }

 //find the integer square root of n
 double sqrt_n = sqrt(n);
 int m = (int) sqrt(n); //round down to nearest integer


 //check if m^2 is a perfect square and greater than or equal to n
 while(!(isPerfectSquare(m*m) && m*m>=n)){
	 m++; //increment m until we find the closest valid m
 }

 printf("Closest integer with a whole number square root for %d is %d\n", n, m);

 return 0;
}


