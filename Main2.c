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
         print_lines(word);
    }
    else{
        print_similar_words(word);
    }

    return 0;
}