#include<stdio.h>
int main(){
 unsigned long long num; //to handle large integers
 int sum = 0;

 printf("Enter a positive integer ");
 scanf("%llu", &num);

 //calculating the sum of digits
 unsigned long long temp = num; //creating a temporary variable to avoid modifying original number
 while (temp>0) {
  sum += temp % 10; //add the last digit of temp to sum
  temp /= 10; //remove the last digit from temp 
 }

 printf("sum of digits of %llu is %d\n",num, sum);

 return 0;
}

