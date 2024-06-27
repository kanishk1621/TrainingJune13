#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char compare(char time1[], char time2[]){
	int d1, m1, y1;
	int d2, m2, y2;
	scanf(time1,"%d%d%d",&d1,&m1,&y1);
	scanf(time2,"%d%d%d",&d2,&m2,&y2);
	if(d1<d2||(d1==d2 && (m1<m2||(m1==m2 && y1<y2)))){
		return 'E';
	}

	else if((d1==d2) &&( m1==m2) &&( y1==y2)){
		return 'S';
	}

	else{
		return 'L';
	}
}

int main(){
	int n;
	printf("Enter the length: ");
	scanf("%d",&n);
	char str[100];
	for(int i=0; i<n; i++){
		char t1[1000];
		char t2[1000];
		scanf("%s%s",t1,t2);
		str[i]=compare(t1,t2);
	}
	for(int i=0; i<n;i++){
		printf("%c\n",str[i]);
	}
	return 0;
}

