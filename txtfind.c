#include <stdio.h>
#include <string.h>
#include "txtfind.h"

int getLine(char s[]){
    char c;
    int i,j;
 for(i=0,j=0; (c=getchar())!=EOF&& c!='\n';i++)
    {
        if(i<LINE-1)
        {
            s[j++]=c;
        }
    }
    if(c=='\n')
    {
        if(i<=LINE-1)
        {
            s[j++]=c;
        }
        i++;
    }
    s[j]='\0';
    return i;
}

int getword (char w[])
{
    char c;
    int i,j;
  for(i=0,j=0; (c=getchar())!=EOF&& c!='\n'&&c!='\t'&&c!=' ';i++)
    {
        if(i<WORD-1)
        {
            w[j++]=c;
        }
    }
    w[j]='\0';
    return i;
}

int substring(char *str1 ,char *str2)
{
    char *c1= str1;
    char *c2= str2;
    while (*c1 != '\0' && *c2 != '\0'){
        while(*c1 != '\0' && *c2 != '\0' && *c1 == *c2){
            c1++;
            c2++;
        }
        if(*c2 == '\0')
        {
            return 1;
        }
        c2 = str2;
        c1++;
        
    }
    return 0;
  
}

int similar(char *s, char *t, int n)
{
   int i=0;
   while(i<=n&&*s != '\0')
   {
       if(*s != *t){
           i++;
       }
       else{
           t++;
       }
       s++;
   }
   if(i<=n && *t == '\0'&& *s == '\0') 
   {
       return 1;
   }
   else
   {
       return 0;
   }
}

void print_lines(char *s)
{
    char line[LINE];
    while(getLine(line))
    {
        if(substring(line,s)){
           printf("%s",line);
        }
    }
}

void print_similar_words(char *str)
{
    char word[WORD];
    while(getword(word))
    {
        if(similar(word,str,1))
        {
            puts(word);
        }
     }
}
