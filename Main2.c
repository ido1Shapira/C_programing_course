#include <stdio.h>
#include <string.h>
#include "txtfind.h"

int main(){
    char word[WORD];
    char option;
    getword(word);
    option = getchar();
    getchar();
    getchar();
    if(option != 'a' && option != 'b'){
        printf(" %c is not an option\n",option);
        return 0;
    }
    if(option == 'a'){
        printf("Printing lines that contains the word '%s':\n\n",word);
        print_lines(word);
    }
    else{
    printf("Printing the similar words for '%s' up to 1 degree of similarity:\n",word);
    print_similar_words(word);
    }

    return 0;
}