#include<stdio.h>
#include<string.h>

void remove_adjacent_duplicates(char *word){
	int len = strlen(word);

	if(len <= 1){
		return;
	}

	int j = 0;

	for (int i =0; i<len; i++){

		if(i<len-1 && word[i] == word[i+1]){
			i++;
		} else {
			word[j++] = word[i];
	}
}

word[j] = '\0';
}

int main(){
	char word[100];

	printf("Enter a word: ");
	scanf("%s",word);

	remove_adjacent_duplicates(word);


	printf("Word after removing adjacent duplicates: %s\n",word);

	return 0;
}

