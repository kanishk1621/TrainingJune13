#include<stdio.h>
int main(){
 int arr[] = {2,1,3,5,4};
 int size = sizeof(arr)/sizeof(arr[0]);
 int max_num = arr[0];
 int min_num = arr[0];

 for(int i=0; i<size; i++){
	if(max_num<arr[i]){
		max_num=arr[i];
	}
 }
 for(int j=0; j<size; j++){
	 if(min_num>arr[j]){
		 min_num=arr[j];
	}
 }

 printf("The maximum element in the array is %d\n", max_num);
 printf("The minimum element in the array is %d\n", min_num);

 return 0;
}
