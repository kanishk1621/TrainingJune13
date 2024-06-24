#include<stdio.h>
int main(){
  int numbers[10];
  int i;

  for(i=0; i<10; i++){
	  numbers[i]=i+1;
  }

  printf("The first 10 natural numbers are: ");
  for(i=0; i<10; i++){
	  printf("%d ", numbers[i]);
  }

  printf("\n");

  return 0;
}
