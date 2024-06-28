#include <stdio.h>
#include <ctype.h>
#include <string.h>

void capitalize(char *sentence){
	int i;

	sentence[0] = toupper(sentence[0]);

	for(i=1; i<strlen(sentence); i++){

		if(isspace(sentence[i])){

			sentence[i+1] = toupper(sentence[i+1]);
		}
	}
}

int main(){
	char sentence[1000];

	printf("Enter a sentence: ");
	fgets(sentence,sizeof(sentence), stdin);

	if (sentence[strlen(sentence)-1] == '\n'){
		sentence[strlen(sentence)-1] = '\0';
	}


	capitalize(sentence);

	printf("Capitalized sentence: %s\n",sentence);
	return 0;
}

